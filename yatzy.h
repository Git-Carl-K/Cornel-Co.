#define size 5
/*-----------------------------------STRUCT-----------------------------------*/
typedef struct ScoreboardColumn {
	int ones;
	int twos;
	int threes;
	int fours;
	int fives;
	int sixes;
	int first_total;
	int bonus;
	int pair;
	int two_pairs;
	int three_of_a_kind;
	int four_of_a_kind;
	int small_straight;
	int large_straight;
	int full_house;
	int chance;
	int yatzy;
	int total_score;
} ScoreboardColumn;

typedef struct Scoreboard {
	char *name;
	ScoreboardColumn score;
} Scoreboard;

typedef struct GameState {
	int num_of_players;
	Scoreboard *players;
	int turn;
	int current_dicepool[5];
} GameState;

typedef struct top_ten {
	char name[20];
	int points;
} top_ten;

typedef struct HighscoreTop10 {
	//oklart
} HighscoreTop10;

/*----------------------------------FUNCTION----------------------------------*/
void play_yatsy();
int game_menu();
int single_player_menu();
int multi_player_menu();
void print_highscore();
void quit_game(GameState *current_game);
void create_scoreboard(GameState *current_game);
void add_player(GameState *current_game);
void new_game(int single_or_multi, GameState *current_game);
void load_game(int single_or_multi);
void save_game();
int compare_small(const void * a, const void * b);
int compare_big(const void * a, const void * b);
void print_pool(int dice_pool[]);
int find(int dice_pool[], int dice_face);
int x_of_a_kind(int dice_pool[], int x_of_a_kind);
int check_small_straigt(int dice_pool[]);
int check_large_straigt(int dice_pool[]);
int check_pairs(int dice_pool[], int pair);
int check_full_house(int dice_pool[]);
int sum_pool(int *dice_pool);
int calculate_first_total(Scoreboard top_column);
int calculate_bonus(Scoreboard bonus_score);
int calculate_total_score(Scoreboard bottom_column);
void fill_scoreboard(GameState *current_game);
void start_game();
int compare_top_ten (const void *a, const void *b);
bool save_top_ten (char *filename,  top_ten players[]);
bool read_top_ten (char *filename,  top_ten fromfile[]);
void print_top_ten (top_ten players[]);
void load_highscore(top_ten *players);
void add_to_highscore(top_ten *players, Scoreboard to_add);
void preset_scoreboard(GameState *current_game);
