#include <stdio.h>
#include <getopt.h>
#include <string.h>

int main(int argc, char **argv) {

    const char *shortOptions = "hvl:";

    static struct option longOptions[] = {
        {"help",    no_argument,       0, 'h'}, 
        {"version", no_argument,       0, 'v'},
        {"list",    required_argument, 0, 'l'},
        {0, 0, 0, 0},
    };

    const char *helpOption = "You can use this program options:\n"
    "-h or --help                          - get message with program options\n"
    "-v or --version                       - get version\n"
    "-l[<val1>,...] or --list=[<num1>,...] - input list of arguments\n";

    bool h_visited = false;
    bool v_visited = false;
    bool l_visited = false;
    
    int index;
    int code;

    while ((code = getopt_long(argc, argv, shortOptions, longOptions, &index)) != -1) {
        switch (code) {
            case 'h': {
                if (!h_visited) {
                    h_visited = true;
                    printf("%s\n", helpOption);
                }
                break;
            }
            case 'v': {
                if (!v_visited) {
                    v_visited = true;                    
                    printf("Version of this program is 1.1.1\n");
                }
                break;
            }
            case 'l': {
                if (!l_visited) {
                    char *args;
                    printf("List of arguments:  ");
                    args = strtok(optarg, ",");
                    while (args != NULL) {
                        printf("%s ", args);
                        args = strtok(NULL, ",");
                    }
                    printf("\n");
                    l_visited = true;
                }
                break;
            }
            default: {
                printf("This argument does'nt exist. Type -h or --help to get message with program options\n");
                return 0;
            }
        }
    }
    return 0;
}
