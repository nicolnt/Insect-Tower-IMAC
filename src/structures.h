#ifndef STRUCTURES_H_
#define STRUCTURES_H_

#ifdef _WIN32
  #include <GL/glew.h>
#else
  #include <GL/gl.h>
  #include <GL/glu.h>
#endif

#include <SDL/SDL.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>

typedef enum MapDataContent {
  MDATA_IMG = 1,
  MDATA_ENERGY = 2,
  MDATA_IN = 4,
  MDATA_OUT = 8,
  MDATA_PATH = 16,
  MDATA_CONSTRUCT = 32,
  MDATA_NODE = 64,
  MDATA_INFOSNODE = 128,
  MDATA_WAVES = 256,
  MDATA_INCONSTRUCTIBLE = 512
} MapDataContent;

typedef enum GameState {
  MAINMENU,
  LEVELPLAY,
  LOSEMENU,
  WINMENU
} GameState;

typedef enum Operations {
  CHK_SUCCESS = 0,
  CHK_NULL = 0,
  CHK_ERROR_ALLOC = 1,
  CHK_ERROR_FILE = 2
} Operations;

typedef enum TypeMonster {
  SOLDER,
  HUGE_SOLDER,
  GERERAL,
  BOSS
} TypeMonster;

typedef enum Sound {
  MUSIQUE,
  TOWER,
  CENTRAL,
  PROJECTILE,
  BEGINLEVEL,
  SOLD,
  HSOLD,
  GENE,
  BOS,
  LOSELEVEL,
  WINLEVEL,
  SNAP,
  HITWOOD,
  ERROR,
  BLEEP
} Sound;

typedef struct Wave {
  int wave_id;
  float timeBeforeNext;
  float freq_pop;
  float random;
  float nextMonster_timer;
  int monster_total;
  TypeMonster* monsters;
  struct Wave* next;
} Wave;

typedef struct ListWaves {
  int wave_total;
  Wave* next;
} ListWaves;


typedef struct RGBcolor {
  unsigned char red;
  unsigned char green;
  unsigned char blue;
} RGBcolor;

typedef struct Node {
  int id;
  int type;
  double x;
  double y;
  int link[4];
} Node;

typedef struct InfosNodes {
  int nbNoeud;
  int entrance_total;
  int idOut;
  int* idEntrees;
  Node* nodes;
  Node** shortPaths;
} InfosNodes;

typedef enum TypeCase {
  LASER = 0,
  MISSILE,
  RADAR,
  ARMEMENT,
  CENTRALE,
  MUNITION,
  TERRAIN,
  CHEMIN,
  NOEUD,
  ENTREE,
  SORTIE,
  INCONSTRUCTIBLE
} TypeCase;

typedef struct ConstructionData {
  TypeCase type;
  int degats;
  int alimentation;
  int energy;
  int cadence;
  int portee;
  int range;
  int valeur_achat;
  int valeur_revente;
} ConstructionData;

typedef struct Chemin {
   Node* node_in;
   Node* node_out;
   int dead_monsters;
   struct Chemin* next;
} Chemin;

typedef struct DataMonsters {
   float PDV;
   float strength;
   double mass;
   int value;
} DataMonsters;

typedef struct ListChemins {
   int nbChemin;
   Chemin* next;
} ListChemins;

typedef struct MapData {
  int Xsplit;
  int Ysplit;
  char* mapFile;
  int energy;
  int argent;
  RGBcolor pathCol;
  RGBcolor nodeCol;
  RGBcolor buildingCol;
  RGBcolor inconstructibleCol;
  RGBcolor inCol;
  RGBcolor outCol;
  unsigned int contentState; 
  InfosNodes* infosNodes;
  ListWaves* listWaves;
  ConstructionData constructionData[6];
  DataMonsters dataMonsters[4];
  ListChemins* listChemins;
  GLuint idGrid;
  GLuint idMap;
  TypeCase* cases;
} MapData;

typedef enum GeneralType {
  TOUR = 1,
  BATIMENT = 2,
  OTHER
} GeneralType;

typedef struct Monster Monster;

typedef enum Bool {
  FALSE = 0,
  TRUE = 1
} Bool;

typedef enum TextureName {
  LASER_TEX,
  MISSILE_TEX,
  RADAR_TEX,
  ARMEMENT_TEX,
  CENTRALE_TEX,
  MUNITION_TEX,
  SOLDER_TEX,
  HUGE_SOLDER_TEX,
  GERERAL_TEX,
  BOSS_TEX,
  PAUSE_TEX,
  PLAY_TEX,
  SPLASH_TEX,
  BUTTON_TEX,
  ADD_TEX,
  REMOVE_TEX,
  GETINFO_TEX,
  PLANK_TEX,
  PLUS_TEX,
  MONEY_TEX,
  POINTER_TEX,
  SHIELD_TEX,
  DAMAGE_TEX,
  CADENCE_TEX,
  SPEED_TEX,
  LIFE_TEX,
  TARGET_TEX,
  FOOD_TEX,
  TERRAIN_1_TEX,
  TERRAIN_2_TEX,
  TERRAIN_3_TEX,
  TERRAIN_4_TEX,
  TERRAIN_5_TEX,
  CHEMIN_1_TEX,
  CHEMIN_2_TEX,
  CHEMIN_3_TEX,
  REINE_TEX,
  MAINMENU_TEX,
  LOSEMENU_TEX,
  WINMENU_TEX,
  WOODPLANKS_TEX,
  FOOD_LOW_TEX,
  FOOD_VERYLOW_TEX,
  FOOD_MEDIUM_TEX,
  FOOD_HIGH_TEX,
  CAILLOU_TEX,
} TextureName;

typedef struct Texture {
  GLuint texture_id;
  int sprite_totalX;
  int sprite_totalY;
} Texture;

typedef struct SpriteTexture {
  TextureName texture_name;
  Bool loop;
  int sprite_numX;
  int sprite_numY;
  Uint32 last_frame;
  int loop_duration;
  float translate_x;
  float translate_y;
} SpriteTexture;

typedef struct TextureText {
  GLuint texture_id;
  float ratio;
} TextureText;


typedef struct Tour {
  TypeCase type;
  int armement;
  int index_case;
  int centrale;
  int munition;
  float rechargement;
  float angle;
  int radar;
  double x;
  double y;
  Uint32 time_tir;
  Monster* targetMonster;
  struct Tour* next;
} Tour;

typedef struct ListTours {
  int nbTours;
  Tour* next;
} ListTours;

typedef enum Action {
  ADD,
  GETINFO,
  REMOVE
} Action;


typedef struct Etat {
  TypeCase type;
  Action action;
  int argent;
} Etat;

typedef enum Orientation {
   HAUT,
   BAS,
   GAUCHE,
   DROITE,
   VERTICAL,
   HORIZONTAL,
   IMMOBILE
} Orientation;

typedef enum Statut {
   ALIVE,
   DEAD
} Statut;

typedef struct Etape {
    Node* node;
    struct Etape* next;
} Etape;


typedef struct Itineraire {
   int nbEtape;
   Etape* next;
} Itineraire;

typedef struct Monster {
  SpriteTexture* sprite_texture;
  float PDV;
  int strength;
  double mass;
  int value;
  int idIn;
  TypeMonster type;
  Statut status;
  float decomposition;
  Orientation orientation;
  double x;
  double y;
  Itineraire* itineraire;
  struct Monster* next; 
} Monster;

typedef enum ProjectileType {
    LAS,
    MIS
} ProjectileType;

typedef struct Projectile {
  Monster* cible;
  ProjectileType type;
  float damage;
  double x;
  double y;
  struct Projectile* next;
} Projectile;

typedef struct ListProjectiles {
    int nbProjectile;
    Projectile* next;
} ListProjectiles;



typedef struct ListMonsters {
   int monster_total;
   Monster* firstMonster;
} ListMonsters;

typedef struct Div {
  int x;
  int y;
  int width;
  int height;
} Div;

typedef enum ButtonName {
  PAUSE_BTN,
  LASER_BTN,
  MISSILE_BTN,
  CENTRALE_BTN,
  MUNITION_BTN,
  ARMEMENT_BTN,
  RADAR_BTN,
  ADD_BTN,
  REMOVE_BTN,
  GETINFO_BTN,
  LEVEL_BTN,
  LEVEL1_BTN,
  LEVEL2_BTN,
  LEVEL3_BTN,
  MAINMENU_BTN,
  REPLAY_BTN
} ButtonName;

typedef enum Display {
  NONE,
  ACTIVE,
  INACTIVE,
  CLICKED,
  DISABLED
} Display;

typedef struct Button {
  int button_id;
  TextureName texture_name;
  Bool display_texture;
  TextureText* texture_texte;
  Div *dimensions;
  Display display;
  struct Button *next;
  ButtonName name;
} Button;

typedef struct Plateau {
  Bool play;
  Etat* joueur;
  GLuint idListInfos;
  GLuint idListIcon;
  GLuint idListMoney;
  Monster *monster_hover;
  int index_case_hover;
  int index_tour_hover;
  ListTours* listTours;
  ListMonsters* listMonsters;
  ListProjectiles* listProjectiles;
  Wave currentWave;
  int *energies;
  Tour **tours;
} Plateau;

typedef enum SectionName {
  BODY,
  FOOTER,
  PLATEAU,
  HEADER,
  TOWER_BUTTONS_SECTION,
  INFO_SECTION,
  MAIN,
  ENDMENU
} SectionName;

typedef struct GUI {
  TextureName texture_name;
  Bool display_texture;
  SectionName name;
  Div *dimensions;
  struct GUI *parent;
  struct GUI *childen;
  struct GUI *next;
  Button *buttons;
} GUI;

typedef enum DefaultListName {
  LASER_DEF,
  MISSILE_DEF,
  RADAR_DEF,
  ARMEMENT_DEF,
  CENTRALE_DEF,
  MUNITION_DEF,
  SOLDER_DEF,
  HUGE_SOLDER_DEF,
  GERERAL_DEF,
  BOSS_DEF,
} DefaultListName;

typedef struct DefaultList {
  GLuint idListInfos;
  GLuint idListIcon;
} DefaultList;

typedef struct Path {
  struct Path *next;
  char *path;
} Path;

typedef struct GameData {
  TextureText* FPS;
  GameState gameState;
  Uint32 beginMomentLevel;
  Texture** textures;
  Mix_Chunk** sound;
  DefaultList **default_list;
  Button *button_hover;
  GUI *bodyGUI;
  GUI *plateauGUI;
  GUI *bottomGUI;
  GUI *topGUI;
  GUI *infoGUI;
  GUI *buttonGUI;
  GUI *mainMenuGUI; 
  GUI *endMenuGUI; 
  Path *path;
} GameData;


extern Plateau* plateau;
extern MapData* mapData;
extern GameData* gameData;

#endif //STRUCTURES_H_
