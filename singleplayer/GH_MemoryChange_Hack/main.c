/**
        Created by: Krzysztof Dobrzynski - k.dobrzynski94@gmail.com
                https://github.com/Sejoslaw


        This program is a memory change hack.
*/

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

/// Name of the Window which will be hacked
char* window_name = "GH_MemoryChange";
/// Window handler
HWND handle_window = NULL;
/// Process Id
DWORD process_id;
/// Process
HANDLE process_handle = NULL;

/// Player addresses to hack - currently must be given from outside.
#define player_pos_x 0x010B1E38
#define player_pos_y 0x00C21E3C

/// Teleport to selected position
int teleport_pos_x = 100;
int teleport_pos_y = 100;

int main(int argc, char *argv[])
{
    /// Set console name
    SetConsoleTitle("GH_MemoryChange_Hack");

    char repeat = 'e'; /// if 'r' than exit loop
    while(repeat != 'r')
    {
        /// Get the Window by the window title
        handle_window = FindWindow(NULL, window_name);

        /// Check if the Window is opened / found
        if(handle_window != NULL)
        {
            printf("Window Found \n");

            /// Get the Window Process Id
            if(GetWindowThreadProcessId(handle_window, &process_id))
                printf("Process Id Found \n");
            else
                printf("Process Id Not Found \n");

            /// Get the needed permission and open the process
            process_handle = OpenProcess(PROCESS_VM_OPERATION | PROCESS_VM_WRITE | PROCESS_VM_READ, 0, process_id);
            if(process_handle != NULL && process_handle != INVALID_HANDLE_VALUE)
            {
                printf("Process Opened \n");

                /// Write positions
                if(WriteProcessMemory(process_handle, (LPVOID)player_pos_x, &teleport_pos_x, sizeof(teleport_pos_x), 0))
                    printf("Position X set to: %i", teleport_pos_x);
                if(WriteProcessMemory(process_handle, (LPVOID)player_pos_y, &teleport_pos_y, sizeof(teleport_pos_y), 0))
                    printf("Position Y set to: %i", teleport_pos_y);

                printf("\n");
            }
            else
                printf("Process Not Opened \n");
        }
        else
            printf("Window Not Found \n");

        /// Pause and Repeat
        scanf("%c", &repeat);
        system("cls");
    }
}

/// Write single position
/*
void write_position(LPVOID base_address, LPCVOID buffer, char axis)
{
    printf("\n");
    printf("Axis %c \n", axis);

    /// Variable to store readed data
    DWORD pointer = base_address;
    ReadProcessMemory(handle_window, base_address, &pointer, sizeof(pointer), NULL);
    printf("Position = %i \n", pointer);

    /// Write memory with new values
    if(WriteProcessMemory(handle_window, base_address, &buffer, sizeof(buffer), NULL))
        printf("Position set to %i \n", buffer);
}
*/
