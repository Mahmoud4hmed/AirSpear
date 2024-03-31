#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <cs50.h>
#include <unistd.h>

void MITM(void);
void Monitor_Mode(void);
void Discover_Devices(void);
void Setup(void);
void Glitch(void);
void end(void);

int main() {
    Glitch();
    printf("Developed by: Mahmoud Ahmed (Glitch)\n\n");
    printf("Contact: mahmoudahmed9go@gmail.com\nFacebook: https://www.facebook.com/mahmoudahmed9go \nInstagram: https://www.instagram.com/mahmoudahmed9go \n\n\n");
    printf("Choose an option:\n\n");
    printf("1. MITM (ARP Spoofing)\n");
    printf("2. Enable Monitor Mode\n");
    printf("3. Discover devices on the network\n");
    printf("4. Setup Wireless Adapter for Monitor Mode (TP-Link V2/V3)\n");
    printf("5. Exit\n");

    int choice = get_int("\nChoice: ");

    // array for storing the funvtions.
    void (*functions[])(void) = {MITM, Monitor_Mode, Discover_Devices, Setup, end};

    for (int i = 0; i < 5; i++) {
        if (choice == i + 1) {
            functions[i]();
        }
    }
}
void MITM(void) {
    char *Interface = NULL;
    char *Router_IP = NULL;
    char *Target_IP = NULL;

    Interface = get_string("Interface: ");
    Router_IP = get_string("Router IP: ");
    Target_IP = get_string("Target IP: ");

    // Define the bash code to be executed.
    char code[1000];
    snprintf(code, sizeof(code), "ettercap -T -S -i %s -M arp:remote /%s// /%s//", Interface, Router_IP, Target_IP);

    // Execute the bash code.
    int status = system(code);

    // Check the status of the bash code.
    if (status == 0) {
        printf("executed successfully.\n");
    } else {
        printf("failed to execute.\n");
    }

    // This is a declaration or statement at the end of the file.
    printf("The end.\n");

    return;
}
void Monitor_Mode(void) {
    const char* const commands[] = {
        "sudo ifconfig wlan0 down",
        "sudo airmon-ng check kill",
        "sudo iwconfig wlan0 mode monitor",
        "sudo ifconfig wlan0 up",
        "clear",
        "iwconfig wlan0"
    };
    // Calculate the number of commands in the array
    int num_commands = sizeof(commands) / sizeof(commands[0]);

    
    for (int i = 0; i < num_commands; i++) {
        int status = system(commands[i]);

        // Calculate the percentage of completion
        int percentage = (i + 1) * 100 / num_commands;

        // Display the progress bar
        printf("%d%% [", percentage);
        int j;
        for (j = 0; j < percentage / 5; j++) {
            printf("=");
        }
        for (; j < 20; j++) {
            printf(" ");
        }
        printf("]\n\n");

        sleep(1); // Wait for 1 second between commands
    }
    system(commands[4]);
    Glitch();
    system(commands[5]);
    return;
}
void Discover_Devices(void) {
    Glitch();

    string range = get_string("Enter The Range [192.168.1.0/24]: ");
    if (range == NULL) {
        system("netdiscover -r 192.168.1.0/24");
    }else{
        // Build the command string using string concatenation
        char command[100];
        snprintf(command, sizeof(command), "netdiscover -r %s", range);
        system(command);
    }
    return;
}
void Setup(void) {
    Glitch();
    printf("\n\nYOU MUST RUN ALL OF THESE STEPS ONE BY ONE!\n\n");
    printf("Choose an option:\n\n");
    printf("Step 1\n");
    printf("Step 2\n");
    printf("Step 3\n");
    printf("Step 4\n");

    int Step = get_int("\nStep: ");

    const char* const S1[] = {
        "sudo apt update && sudo apt upgrade",
        "sudo apt install bc",
        "sudo apt-get install build-essential",
        "sudo apt-get install libelf-dev",
    };
    
    const char* const S3[] = {
        "sudo apt install dkms",
        "sudo rmmod r8188eu.ko",
        "git clone https://github.com/KanuX-14/rtl8188eus.git",
        "cd rtl8188eus && sudo sh -c 'echo \"blacklist r8188eu\" > /etc/modprobe.d/realtek.conf'",
    };

    const char* const S4[] = {
        "sudo apt update",
        "cd rtl8188eus",
        "sudo make",
        "sudo make install",
        "sudo modprobe 8188eu",
    };

    int S1_size = sizeof(S1) / sizeof(S1[0]);
    int S3_size = sizeof(S3) / sizeof(S3[0]);
    int S4_size = sizeof(S4) / sizeof(S4[0]);



    if (Step == 1) {
        Glitch();
        for (int i = 0; i < S1_size; i++) {
            int status = system(S1[i]);
        }
        Glitch();
        printf("\n==============================================");
        printf("\nStep 1 completed successfully.\n");
        printf("Continue with Step 2.\n");
        printf("==============================================\n");
        main();
    }
    else if(Step == 2){
        Glitch();
        printf("Try either of these ways to see which works:\n\n");
        printf("Way 1\n");
        printf("Way 2\n");
        char *way = get_string("\nWay: ");
        if (way != NULL && way[0] == '1'){
            system("sudo apt-get install linux-headers-`uname -r`");
            printf("\nIF YOU GET AN ERROR JUST TRY THE OTHER WAY!\n");
            sleep(5);
            main();
        }
        else if (way != NULL && way[0] == '2'){
            system("sudo apt-get install linux-headers-5.10.0-kali6-amd64");
            main();
        }else{
            end();
        }
    }
    else if(Step == 3){
        printf("\n==============================================\n");
        printf("Your device will be restarted after this step!\n");
        printf("Make sure you are connected to the internet!\n");
        printf("==============================================\n\n");
        sleep(5);

        for (int i = 0; i < S3_size; i++) {
        int status = system(S3[i]);
        }
        printf("\n\n==============================================\n");
        printf("Step 3 completed successfully.\n");
        printf("Continue with Step 4 after reboot.\n");
        printf("==============================================\n\n");
        sleep(5);
        system("reboot");
        

    }
    else if(Step == 4){
        Glitch();
        for (int i = 0; i < S4_size; i++) {
            int status = system(S4[i]);
        }
        Glitch();
        string press_str = get_string("Enter 1 to enable monitor mode or any other potion to quit: ");
    if (press_str != NULL) {
        int press = atoi(press_str);
        if (press == 1) {
            Monitor_Mode();
            printf("Monitor mode enabled.\n");
        } else {
            printf("Quiting..\n");
            sleep(3);
        }
    }
        printf("\nGood bye!\n");
        main();
    }
    return;
}
void Glitch(void)
{
    system("clear");
    printf("\n ▄▄▄▄▄▄▄ ▄▄▄     ▄▄▄ ▄▄▄▄▄▄▄ ▄▄▄▄▄▄▄ ▄▄   ▄▄ \n█       █   █   █   █       █       █  █ █  █\n█   ▄▄▄▄█   █   █   █▄     ▄█       █  █▄█  █\n█  █  ▄▄█   █   █   █ █   █ █     ▄▄█       █\n█  █ █  █   █▄▄▄█   █ █   █ █    █  █   ▄   █\n█  █▄▄█ █       █   █ █   █ █    █▄▄█  █ █  █\n█▄▄▄▄▄▄▄█▄▄▄▄▄▄▄█▄▄▄█ █▄▄▄█ █▄▄▄▄▄▄▄█▄▄█ █▄▄█\n\n\n");
    printf("=============================================================\n");
    printf("             _                                            \n");
    printf("     /\\     (_)                                           \n");
    printf("    /  \\     _   _ __   ___   _ __     ___    __ _   _ __ \n");
    printf("   / /\\ \\   | | | '__| / __| | '_ \\   / _ \\  / _` | | '__|\n");
    printf("  / ____ \\  | | | |    \\__ \\ | |_) | |  __/ | (_| | | |   \n");
    printf(" /_/    \\_\\ |_| |_|    |___/ | .__/   \\___|  \\__,_| |_|   \n");
    printf("                             | |                          \n");
    printf("                             |_|                          \n\n\n");
}
void end(void)
{
    exit(0);
}