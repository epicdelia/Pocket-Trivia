#include <stdio.h>
#include <allegro5/allegro.h>
#include "allegro5/allegro_primitives.h"
#include "allegro5/allegro_primitives.h"
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>

const float FPS = 60;
const int SCREEN_W = 640;
const int SCREEN_H = 480;
const int BOUNCER_SIZE = 32;

int main(int argc, char **argv) {

	int numberOfCorrectAnswers = 0;
	int numberOfIncorrectAnswers = 0;
	int mousex, mousey, leftClick;
	int textcolor, bgcolor, buttoncolor;
	int leftClickBeingHeld;
	int currentKey, scancode, ascii;
	int startScreenMode = 1;
	int mainMenuMode = 0;
	int selectChapterMode = 0;
	int selectUnitMode = 0;
	int selectNumberOfQuestionsMode = 0;
	int numberOfQuestions;
	int gameMode = 0;
	int endScreenMode = 0;
	int inputIndex;
	int currentQuestion;
	int newQuestionNeeded = 1;
	int isFirstQuestion = 1;
	int questionsDone[220];
	char input[10];
	char filename[14];
	char textLine[200];

	enum MYKEYS {
		KEY_UP, KEY_DOWN, KEY_LEFT, KEY_RIGHT
	};

	ALLEGRO_DISPLAY *display = NULL;
	ALLEGRO_EVENT_QUEUE *event_queue = NULL;
	ALLEGRO_TIMER *timer = NULL;
	ALLEGRO_BITMAP *bouncer = NULL;
	float bouncer_x = SCREEN_W / 2.0 - BOUNCER_SIZE / 2.0;
	float bouncer_y = SCREEN_H / 2.0 - BOUNCER_SIZE / 2.0;
	bool key[4] = { false, false, false, false };
	bool redraw = true;
	bool doexit = false;

	if (!al_init()) {
		fprintf(stderr, "failed to initialize allegro!\n");
		return -1;
	}

	if (!al_install_keyboard()) {
		fprintf(stderr, "failed to initialize the keyboard!\n");
		return -1;
	}

	timer = al_create_timer(1.0 / FPS);
	if (!timer) {
		fprintf(stderr, "failed to create timer!\n");
		return -1;
	}

	display = al_create_display(SCREEN_W, SCREEN_H);
	if (!display) {
		fprintf(stderr, "failed to create display!\n");
		al_destroy_timer(timer);
		return -1;
	}

	bouncer = al_create_bitmap(BOUNCER_SIZE, BOUNCER_SIZE);
	if (!bouncer) {
		fprintf(stderr, "failed to create bouncer bitmap!\n");
		al_destroy_display(display);
		al_destroy_timer(timer);
		return -1;
	}

	al_init_font_addon();
	al_init_ttf_addon();


	al_set_target_bitmap(bouncer);

	al_clear_to_color(al_map_rgb(255, 0, 255));

	al_set_target_bitmap(al_get_backbuffer(display));

	event_queue = al_create_event_queue();
	if (!event_queue) {
		fprintf(stderr, "failed to create event_queue!\n");
		al_destroy_bitmap(bouncer);
		al_destroy_display(display);
		al_destroy_timer(timer);
		return -1;
	}

	al_register_event_source(event_queue, al_get_display_event_source(display));

	al_register_event_source(event_queue, al_get_timer_event_source(timer));

	al_register_event_source(event_queue, al_get_keyboard_event_source());

	al_clear_to_color(al_map_rgb(0, 0, 0));

	al_start_timer(timer);

	ALLEGRO_FONT *font24 = al_load_ttf_font("arial.ttf", 24, 0);

	al_clear_to_color(al_map_rgb(0, 0, 0));
	al_draw_text(font24, al_map_rgb(255, 0, 255), 50, 50, 0, "Your Text Here!");
	al_flip_display();

	al_rest(5.0);

	al_destroy_bitmap(bouncer);
	al_destroy_timer(timer);
	al_destroy_display(display);
	al_destroy_event_queue(event_queue);

	return 0;
}

void start_game() {


}

void printScore() {

}
void correctAnswer() {
}
void incorrectAnswer() {
	printScore();
}