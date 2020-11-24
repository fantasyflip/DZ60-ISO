//----------------------
//------- HEADER -------
//----------------------

#include QMK_KEYBOARD_H
#include </Users/philipp/qmk_firmware/quantum/keymap_extras/keymap_german.h>
#include </Users/philipp/qmk_firmware/quantum/keymap_extras/sendstring_german.h>

//-------------------------
//------- FUNCTIONS -------
//-------------------------

//HexText
#define STRING_SIZE_HEX 3

//Keycode and Char Array
struct t_KCnChar
{
  uint16_t KC;
  char c;
} a_Cast [] = {{KC_0, '0'}, {KC_1, '1'}, {KC_2, '2'}, {KC_3, '3'}, {KC_4, '4'}, {KC_5, '5'}, {KC_6, '6'}, {KC_7, '7'}, {KC_8, '8'}, {KC_J, '9'}, {KC_A, 'a'}, {KC_B, 'b'}, {KC_C, 'c'}, {KC_D, 'd'}, {KC_E, 'e'}, {KC_F, 'f'}, {KC_G, 'g'}, {KC_H, 'h'}, {KC_I, 'i'}, {KC_J, 'j'}, {KC_K, 'k'}, {KC_L, 'l'}, {KC_M, 'm'}, {KC_N, 'n'}, {KC_O, 'o'}, {KC_P, 'p'}, {KC_Q, 'q'}, {KC_R, 'r'}, {KC_S, 's'}, {KC_T, 't'}, {KC_U, 'u'}, {KC_V, 'v'}, {KC_W, 'w'}, {KC_X, 'x'}, {KC_Y, 'z'}, {KC_Z, 'y'}};

//Saving Array
char hex[STRING_SIZE_HEX];

//Function to Convert Char Value to Hex Value
char *Char2Hex (char c)
{
  int i_ASCII = c;

  char *p_hex = malloc(sizeof *p_hex);

  sprintf(hex, "%x", i_ASCII);

  p_hex = &hex[0];

  return p_hex;
};

//Function for Printing the Hex-Value
void prHex (char c)
{
  char *p = Char2Hex(c);

  for (int i = 0; i < STRING_SIZE_HEX; i++)
  {
    send_char(p[i]);
  }
};

//BinText

#define STRING_SIZE_BIN 9

//Hex Value and Binary Value Array
struct t_HEXnBIN
{
  char hex;
  int bin;
} a_BinCast [] = {{'0', 0000}, {'1', 0001}, {'2', 0010}, {'3', 0011}, {'4', 0100}, {'5', 0101}, {'6', 0110}, {'7', 0111}, {'8', 1000}, {'9', 1001}, {'a', 1010}, {'b', 1011}, {'c', 1100}, {'d', 1101}, {'e', 1110}, {'f', 1111}};

char bin [STRING_SIZE_BIN];

//Function to Convert Hex Value to Binary Value
char *Hex2Bin (char *p_hex)
{
  char *p_bin = malloc(sizeof *p_bin);
  long int binVal = 12345678;
  int BinDig1 = 2;
  int BinDig2 = 3;

  for (int i = 0; i < 2; i++)
  {
    char Hex = p_hex[i];
    for (int i = 0; i < 16; i++)
    {
      if (Hex == a_BinCast[i].hex)
      {
        if (i == 0)
        {
          BinDig1 = a_BinCast[i].bin;
        }
        if (i == 1)
        {
          BinDig2 = a_BinCast[i].bin;
        }
        i = 16;
      }
    }

  }

  binVal = (BinDig1 * 10000) + BinDig2;

  sprintf(bin,"%ld",binVal);

  p_bin = &bin[0];

  return p_bin;
};

//Function to Convert Int to Char Array
char *Int2CharArray(int number)
{
  int n = log10(number) + 1;
  int i;

  char *intArray = calloc(n, sizeof(char));

  for (i = 0; i < n; ++i, number /= 10)
  {
    intArray[i] = number % 10;
  }

  return intArray;
}

//Function for printing the Binary Value
void prBin (char c)
{
  char *p = Hex2Bin(Char2Hex(c));
  for(int i = 0; i < STRING_SIZE_BIN; i++)
  {
    send_char(p[i]);
  }
};

//----------------------------
//------- LAYER-DEFINE -------
//----------------------------

enum keyboard_layers {
  _BL = 0,  // Base Layer
  _FL,      // Function Layer
  _ML,      // Macro Layer
  _AL,      // Adjustment Layer
};

//----------------------
//------- MACROS -------
//----------------------


enum custom_keycodes
{
  MKC_EMY = SAFE_RANGE,     // Keycode for unmapped Buttons
  MKC_HEXTXT,               // Keycode for writing in Hextext
  MKC_PRTMAP,               // Opens this FW-Code
  MKC_SPTFY,                // Opens Spotify (REQUIRED: Spotify.lnk in Start-Menu)
  MKC_RBW,                  // Set RGB to Rainbow Cycle
  MKC_TNTTXT,               // fOr tHe mAxImUm tOxIcItY
  MKC_WDTXT,                // S O  E V E R Y B O D Y  U N D E R S T A N D S
  MKC_TWNK,                 // RGB-Mode: Twinkle
  MKC_BINTXT,               // Keycode for writing Binary Values
  MKC_NWD,                  // Create new Desktop
  MKC_CLD,                  // Close Desktop
  MKC_NXD,                  // Next Desktop
  MKC_LSD,                  // Last Desktop
  /*
  MKC_TBLFLP,               // (╯°□°）╯︵ ┻━┻)  Emoji
  MKC_FU,                   // ┌П┐(◉_◉)┌П┐ Emoji
  MKC_IDC,                  // ¯\_(ツ)_/¯ Emoji
  MKC_TBLRST,               // ┬──┬◡ﾉ(° -°ﾉ)  Emoji
  MKC_LNY,                  // ( ͡° ͜ʖ ͡°)  Emoji
  MKC_UCMA,                 // Unicode Input Mac OS
  MKC_UCWI                  // Unicode Input Windows using WinCompose

  #define UCKC_THNK X(E_THNK) //Defining Keycode for Think Emoji
  #define UCKC_CLWN X(E_CLWN) //Defining Keycode for Clown Emoji
  */
};


//RGB Lighting Variables for saving values
uint8_t Mode = 0;
uint8_t hue = 0;
uint8_t sat = 0;
uint8_t val = 0;
uint8_t spd = 0;

//HexText Struct
static struct
{
  bool on;
  bool first;
  int LineCounter;
} t_hextext = {false, false, 0};

//BinText bool
//static bool binText = false;

//Processing Macros
bool process_record_user(uint16_t keycode, keyrecord_t *record)
{
  //Taunttext Bool
  static bool b_taunttext = false;

  //Tauntext Syntax
  if (b_taunttext)
  {
    if (record->event.pressed)
    {
      switch (keycode)
      {
        case KC_A...KC_Z:
        case DE_UDIA:
        case DE_ADIA:
        case DE_ODIA:
          tap_code(KC_CAPS);
          break;
      }
    }
  }

  //Widetext Struct
  static struct
  {
    bool on;
    bool first;
  } t_widetext = {false, false};

  //Widetext Syntax
  if (t_widetext.on)
  {
    if (record->event.pressed)
    {
      switch (keycode)
      {
        case DE_SS:
        case KC_A...KC_0:
        case DE_UDIA:
        case DE_ADIA:
        case DE_ODIA:
          if (t_widetext.first)
          {
            t_widetext.first = false;
          }
          else
          {
            send_char(' ');
          }
          break;
        case KC_SPC:
          if (t_widetext.first)
          {
            t_widetext.first = false;
          }
          else
          {
            send_char(' ');
            send_char(' ');
          }
          break;
        case KC_ENT:
          t_widetext.first = true;
          break;
        case KC_BSPC:
          send_char('\b'); // backspace for deleting Space and Character
          break;
      }
    }
  }

  switch (keycode)
  {
    //Unmapped Buttons
    case MKC_EMY:
    {
      if (record->event.pressed)
      {
        //Pushing Unmapped Button

        //Saving Values
        Mode = rgblight_get_mode();
        hue = rgblight_get_hue();
        sat = rgblight_get_sat();
        val = rgblight_get_val();
        spd = rgblight_get_speed();

        //Set bottom Line of LEDs RED and Lighting Mode to 'Static'
        rgblight_mode(1);
        rgblight_sethsv_range(HSV_RED, 8, 16);
      }
      else
      {
        //Releasing Unmapped Button

        //Setting saved Values
        rgblight_mode(Mode);
        rgblight_sethsv_range(hue, sat, val, 8, 15);
        rgblight_set_speed(spd);
      }
      return false;
      break;
    }

    //Activating Hextext
    case MKC_HEXTXT:
    {
      if (record->event.pressed)
      {
        t_hextext.on = !t_hextext.on;
        t_hextext.first = true;
      }
      return false;
      break;
    }

    //Opening THIS Syntax
    case MKC_PRTMAP:
    {
      //Opening Git-Hub-Code of Keymapping
      if (record->event.pressed)
      {
        //Pushing: Win-Run
        SEND_STRING(SS_LGUI("r"));
      }
      return true;
      break;
    }

    //Opening Spotify
    case MKC_SPTFY:
    {
      //Opening Spotify
      if (record->event.pressed)
      {
        //Pushing: Win-Run
        SEND_STRING(SS_LGUI("r"));
      }
      return true;
      break;
    }

    //Setting RGB LEDs to Rainbow Cycle
    case MKC_RBW:
    {
      if (record->event.pressed)
      {
        rgblight_mode(9);
      }
      return false;
    }

    //Activating Taunttext
    case MKC_TNTTXT:
    {
      if (record->event.pressed)
      {
        b_taunttext = !b_taunttext;
      }
      return false;
    }

    //Activating Widetext
    case MKC_WDTXT:
    {
      if (record->event.pressed)
      {
        t_widetext.on = !t_widetext.on;
        t_widetext.first = true;
      }
      return false;
    }

    //Setting RGB LEDs to Rainbow Cycle
    case MKC_TWNK:
    {
      if (record->event.pressed)
      {
        rgblight_mode(RGBLIGHT_MODE_TWINKLE + 1);
        rgblight_sethsv(170, 255, 255);
      }
      return false;
    }

    //Activating BinText
    case MKC_BINTXT:
    {
      if (record->event.pressed)
      {
        //binText = !binText;

        prBin('b');
      }
      return true;
    }

    //Create New Desktop
    case MKC_NWD:
    {
      if (record->event.pressed)
      {
        SEND_STRING(SS_LGUI(SS_LCTL("d")));
      }
      return false;
    }

    //Close current Desktop
    case MKC_CLD:
    {
      if (record->event.pressed)
      {
        SEND_STRING(SS_LGUI(SS_LCTL(SS_TAP(X_F4))));
      }
      return false;
    }

    //Switch to next Desktop
    case MKC_NXD:
    {
      if (record->event.pressed)
      {
        SEND_STRING(SS_LGUI(SS_LCTL(SS_TAP(X_RIGHT))));
      }
      return false;
    }

    //Switch to last Desktop
    case MKC_LSD:
    {
      if (record->event.pressed)
      {
        SEND_STRING(SS_LGUI(SS_LCTL(SS_TAP(X_LEFT))));
      }
      return false;
    }
  }
  return true;
};

void post_process_record_user(uint16_t keycode, keyrecord_t *record)
{
  //HexText Syntax
  if (t_hextext.on)
  {
    if (record->event.pressed)
    {

    }
    else
    {
      switch (keycode)
      {
        case KC_A...KC_0:
        {
          unregister_code(KC_LSFT);
          unregister_code(KC_RSFT);
          for (int i = 0; i < 36; i++)
          {
            if (a_Cast[i].KC == keycode)
            {
              send_char('\b');
              t_hextext.LineCounter = t_hextext.LineCounter + 1;
              if (t_hextext.first)
              {
                SEND_STRING("0x");
                t_hextext.first = false;
                t_hextext.LineCounter = 1;
              }
              prHex(a_Cast[i].c);
            }
          }
         break;
        }
        case KC_SPC:
        {
          //Remove break if "0x" in front of every word is wanted!
          break;
        }
        case KC_ENT:
        {
          t_hextext.first = true;
          break;
        }
        case KC_BSPC:
        {
          if (t_hextext.first)
          {

          }
          else
          {
            if (t_hextext.LineCounter == 1)
            {
              for (int i = 0; i < 3; i++)
              {
                send_char('\b');
              }
              t_hextext.first = true;
            }
            else
            {
              send_char('\b');
            }
            t_hextext.LineCounter = t_hextext.LineCounter - 1;
          }
        }
      }
    }
  }

/*
  if (binText)
  {
    if (record->event.pressed)
    {

    }
    else
    {
      switch(keycode)
      {
        case KC_A...KC_0:
        {

        }
      }
    }

  }
  */

  //Processing Macros
  switch(keycode)
  {
    //Print Keymaplink
    case MKC_PRTMAP:
    {
      if (!record->event.pressed)
      {
        SEND_STRING("https://bit.ly/35WFklO\n");
        break;
      }
    }

    //Open Spotify
    case MKC_SPTFY:
    {
      if (!record->event.pressed)
      {
        SEND_STRING("%APPDATA%/Microsoft/Windows/Start Menu/Programs/Spotify.lnk\n");
        break;
      }
    }
  }
};

//---------------------------------
//------- UNDERGLOW-MAPPING -------
//---------------------------------

// Defining-Lighting-Layer: Light Left LEDs RED when caps lock is active
const rgblight_segment_t PROGMEM UG_CAPSL[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 1, HSV_RED},       // Light LED 1 in RED
    {15, 1, HSV_RED}       // Light LED 16 in RED
);

// Defining-Lighting-Layer: Light bottom row LEDs in cyan when keyboard layer 1 is active
const rgblight_segment_t PROGMEM UG_FNL[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 8, HSV_CYAN}      // Light LED 0-8 in CYAN
);

// Defining-Lighting-Layer: Light bottom row LEDs in yellow when keyboard layer 3 is active
const rgblight_segment_t PROGMEM UG_ADJL[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 8, HSV_YELLOW}      // Light LED 0-8 in YELLOW
);

// Defining-Lighting-Layer: Light bottom row LEDs in green when keyboard layer 2 is active
const rgblight_segment_t PROGMEM UG_MACROL[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 8, HSV_GREEN}    // Light LED 0-8 in GREEN
);

// Light Layer Array
const rgblight_segment_t* const PROGMEM UG_Layers[] = RGBLIGHT_LAYERS_LIST(
    //Overwriting layers from Bottom to Top
    UG_FNL,
    UG_MACROL,
    UG_ADJL,
    UG_CAPSL
);

void keyboard_post_init_user(void) {
    // Enable the LED layers
    rgblight_layers = UG_Layers;
}

//Checking Layer State and Setting the Lighting Layer accordingly
layer_state_t layer_state_set_user(layer_state_t state)
{
  rgblight_set_layer_state(0, layer_state_cmp(state, 1));
  rgblight_set_layer_state(1, layer_state_cmp(state, 2));
  rgblight_set_layer_state(2, layer_state_cmp(state, 3));
  return state;
}

//Checking Caps-Lock and Activating Caps-Lock Layer accordingly
bool led_update_user(led_t led_state)
{
  rgblight_set_layer_state(3, led_state.caps_lock);
  return true;
}

//-----------------------
//------- MAPPING -------
//-----------------------

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  //LAYER 0
  [_BL] = LAYOUT_60_iso(
    KC_ESC,  DE_1,    DE_2,    DE_3,    DE_4,    DE_5,    DE_6,    DE_7,    DE_8,    DE_9,    DE_0,    DE_SS, DE_ACUT,  KC_BSPC,
    KC_TAB,  DE_Q,    DE_W,    DE_E,    DE_R,    DE_T,    DE_Z,    DE_U,    DE_I,    DE_O,    DE_P,    DE_UDIA, DE_PLUS,
    KC_CAPS,   DE_A,    DE_S,    DE_D,    DE_F,    DE_G,    DE_H,    DE_J,    DE_K,    DE_L,    DE_ODIA, DE_ADIA, DE_HASH, KC_ENT,
    KC_LSFT, DE_LABK, DE_Y,    DE_X,    DE_C,    DE_V,    DE_B,    DE_N,    DE_M,    DE_COMM, DE_DOT,  DE_MINS, KC_RSFT,
    KC_LCTL, KC_LGUI, KC_LALT,                   KC_SPC,                                      KC_RALT, TT(1), TT(2),   KC_RCTL
  ),

  //LAYER 1
  [_FL] = LAYOUT_60_iso(
    KC_GRV, KC_F1,  KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,  KC_F7,  KC_F8,  KC_F9,  KC_F10, KC_F11, KC_F12,  KC_DEL,
    MKC_EMY,  KC_HOME,  KC_UP,   KC_END,   MKC_EMY,   MKC_EMY,   MKC_EMY,  MKC_EMY,  MKC_EMY,  MKC_EMY,  MKC_EMY,  MKC_EMY,  KC_KP_PLUS,
    MKC_EMY,  KC_LEFT,  KC_DOWN,   KC_RIGHT,   MKC_EMY,   MKC_EMY,   MKC_EMY,  MKC_EMY,  MKC_EMY,  MKC_EMY,  MKC_EMY,  MKC_EMY,  MKC_EMY,   MKC_EMY,
    MKC_EMY,  MKC_EMY,  MKC_EMY,   MKC_EMY,   MKC_EMY,   MKC_EMY,   MKC_EMY,  MKC_EMY,  MKC_EMY,  MKC_EMY,  MKC_EMY,  MKC_EMY,  MKC_EMY,
    MKC_EMY,  MKC_EMY,  MKC_EMY,                   MKC_EMY,                                     MKC_EMY,  TT(1),  TT(3),   MKC_EMY
  ),

  //LAYER 2
  [_ML] = LAYOUT_60_iso(
    MKC_EMY,  KC_VOLD,  KC_MPRV,   KC_MPLY,   KC_MNXT,   KC_VOLU,   KC_MUTE,  MKC_EMY,  MKC_EMY,  MKC_EMY,  MKC_EMY,  MKC_EMY,  RGB_TOG,   MKC_EMY,
    MKC_EMY,  MKC_EMY,  MKC_EMY,   MKC_EMY,   MKC_EMY,   MKC_EMY,   MKC_EMY,  MKC_EMY,  MKC_EMY,  MKC_EMY,  MKC_EMY,  MKC_NWD,  MKC_EMY,
    MKC_EMY,  MKC_EMY,  MKC_SPTFY,   MKC_EMY,   MKC_EMY,   MKC_EMY,   MKC_EMY,  MKC_EMY,  MKC_EMY,  MKC_EMY,  MKC_LSD,  MKC_CLD,  MKC_NXD,   MKC_EMY,
    MKC_TNTTXT,  MKC_EMY,  MKC_EMY,   MKC_HEXTXT,   MKC_EMY,   MKC_EMY,   MKC_BINTXT,  MKC_EMY,  MKC_PRTMAP,  MKC_EMY,  MKC_EMY,  MKC_EMY,  MKC_EMY,
    MKC_EMY,  MKC_RBW,  MKC_EMY,                   MKC_WDTXT,                                     MKC_EMY,  MKC_EMY,  TT(2),   MKC_EMY
  ),

  //LAYER 3
  [_AL] = LAYOUT_60_iso(
    MKC_EMY,  MKC_EMY,  MKC_EMY,   MKC_EMY,   MKC_EMY,   MKC_EMY,   MKC_EMY,  MKC_EMY,  MKC_EMY,  MKC_EMY,  MKC_EMY,  MKC_EMY,  MKC_EMY,   MKC_EMY,
    MKC_EMY,  RGB_TOG,  RGB_MOD,   RGB_HUI,   RGB_HUD,   RGB_SAI,   RGB_SAD,  RGB_VAI,  RGB_VAD,  MKC_EMY,  MKC_EMY,  MKC_EMY,  MKC_EMY,
    MKC_EMY,  BL_TOGG,  BL_STEP,   BL_INC,   BL_DEC,   MKC_EMY,   MKC_EMY,  MKC_EMY,  MKC_EMY,  MKC_EMY,  MKC_EMY,  MKC_EMY,  MKC_EMY,   MKC_EMY,
    MKC_EMY,  MKC_RBW,  MKC_TWNK,   MKC_EMY,   MKC_EMY,   MKC_EMY,   RESET,  MKC_EMY,  MKC_EMY,  MKC_EMY,  MKC_EMY,  MKC_EMY,  MKC_EMY,
    MKC_EMY,  MKC_EMY,  MKC_EMY,                   MKC_EMY,                                     MKC_EMY,  MKC_EMY,  TT(3),   MKC_EMY
  ),
};
