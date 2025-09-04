#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <unistd.h>     // fork, execvp
#include <sys/wait.h>   // waitpid
#include <cstring>  
#include<filesystem> 
#include <cstring>
#include <unistd.h>
#include <arpa/inet.h>
#include <readline/readline.h>
#include <readline/history.h>  // c_str

using namespace std;

void art()
{
     vector<string> art = {
        "```````````````````````````````````````^^``````````````````````````````````````````````",
        "```````````````````````````````````^kz`^\"````````````````````````````````````````````",
        "``````````````````````````\"C@@*J{;``I@b`:<```````````````````````````````````````````",
        "````````````````````````````[@@@@@@QI@@#l[```````````````````````````````````````````",
        "``````````````````````````,xzb@@@@@@@C@@w[```````````````````````````````````````````",
        "```````````````````````````;)@@@@@@@@@@@@f\"``````````````````````````````````````````",
        "```````````````````^\"<nd@@@@@@#@@@@@@@@@@@@@*!^``````````````````````````````````````",
        "```````````````````^>fB@@@@@@@@@@@@@@@@@@@@@@@m`^!>>;\"^^`````````````````````````````",
        "``````````````````````^,(@@@@@@@@@@@@@@@@@@@@@@@@@@@@@M{\"````````````````````````````",
        "```````````````````^^:Ii<~~W@@@@@@@@@@@@@@@@@@@@@@@Q!\"^``````````````````````````````",
        "```````````````````````^>rw*@@@@@@@@@@@*@@@@@@@@@@@@@@@@@W;``````````````````````````",
        "```````````````````^!Jb@@@@@@@@@@@Q$@dZ)w@@d@@o@@@@@@di^`````````````````````````````",
        "``````````````````````````^_b@@#*W*@px})m@dWBdm@@@|^`````````````````````````````````",
        "```````````````````````````^Io@@czf!cM1(d@Qjhdb@@C;``````````````````````````````````",
        "```````````````````````````````\"~x}<)x/jQrcZY(,``````````````````````````````````````",
        "`````````````````````````````^\"_j/vf1}/OmZdddd[kz!,^`````````````````````````````````",
        "`````````````````````````^:>}dddC<f|vX/fpddddmdddddd/i\"``````````````````````````````",
        "```````````````````````iYdddddddJvx|fOOZmmzvvOmdddddddd|\"````````````````````````````",
        "`````````````````````\"/hdddddddd@ozjftwZxtfcdWBWkdddddd@B|~^`````````````````````````",
        "```````````````````^+MW@dddddddd$BWWWWWWWWWWWBW@ddddkd@@$W^`````````````````````````",
        "````````````````````:bW$dddddddd$WWWWWWWWWW$@@@@ddddkk@@@w;``````````````````````````",
        "`````````````````````~WBMd*ddddddo@@@$$@@@@@@@ddddddB@@@rf^``````````````````````````",
        "`````````````````````,}Z@@Wdddddddd@@@@@@@@@hddddddM@Bwwvx```````````````````````````",
        "`````````````````````!/rtd@dddddddddd@@@@@ddddddddddm)1CZJ^``````````````````````````",
        "`````````````````````ij{_]Yddddddddddddodddddddddb*d[l]Yp}I``````````````````````````",
        "````````````````````^!]]_}YZddddddk#dddddhkdddd*$kzp|+[COc{;`````````````````````````",
        "````````````````````^>[-1xOddfYMMWWWWWWWMW$@@@@@@l,(Qf-{|t0fI````````````````````````",
        "```````````````````^<_(+rZZd(^/MMMMMMWBWWWMMMWBMM:`^)f}+ij#@d}-l^````````````````````",
        "```````````````````\"j{_~cvjdr^}MMMMMMMMMMMW$@@@@@:``{C/1*MMMhJj1f<```````````````````",
        "```````````````````<MMdcCYdd\",dddddbb*k#o*M*W#h@Wl```;1W@MM*CfxcQ(I``````````````````",
        "```````````````^__|#MMMModp!`rddddddddd@dddddaddbb\"````\">@@rfXJC0f:``````````````````",
        "``````````````I+(JXdbMMB@r\"`IddddddddddBddddddddddd^`````\"<vQOZz1,```````````````````",
        "`````````````^[|c]cnrd*@r^``Jdddddddddd*ddddddddddd|``````^:i;\"^`````````````````````",
        "``````````````!/1xX{0zJ~```^dddddddddddddddddddddddw,````````````````````````````````",
        "````````````````^!fcxc,```^)ddddddddddWdodddddddddddX^```````````````````````````````",
        "`````````````````````````\"ZddddddddddddaddddddddddddO,```````````````````````````````",
        "````````````````````````IdddddddddddddW@ddddddddddddd{```````````````````````````````",
        "```````````````````````:mddddddddddddM*h*dddddddddddbv\"``````````````````````````````",
        "``````````````````````^|ddddddddddddodd_dhddddddddddbBt^`````````````````````````````",
        "``````````````````````:YdddddddddddddW$,YdddddddddddhWB-^````````````````````````````",
        "``````````````````````~ddddddddddddbMWi^-dddddddddddhkdb;````````````````````````````",
        "`````````````````````^xdddddddddddddMb``:Xdddddddddddddd]````````````````````````````",
        "`````````````````````:YddddddddddddM@;``^jddddddddddddddk^```````````````````````````",
        "````````````````````^)dddddddddddkWWZ\"``^tddddddddddddoddI```````````````````````````",
        "```````````````````^+ddddbddddddokd*]^```^{dddddddddddWddd\"``````````````````````````",
        "```````````````````^]dddddddddddddkW+````,Zddddddddd*dddd~``````````````````````````",
        "```````````````````+dddddddddddddhb>``````\"Odddddddaddddd@d+`````````````````````````",
        "``````````````````+ddddddddddddd*Bj````````]ddddddddddhddbdd,````````````````````````",
        "`````````````````Iddddddddddddddbz,`````````fdddddddddddhddk^````````````````````````",
        "`````````````````:dddddddddddddad:``````````,ddddddddddodd*k\"````````````````````````",
        "`````````````````:dddddddddddbkdY````````````Ydddddddd*kdh@h]````````````````````````",
        "`````````````````-dddddkbddddd*d:````````````^dddddddoddhh#b,````````````````````````",
        "`````````````````^|dddddddhd@@~,``````````````\"Jdddddddddd@@>````````````````````````",
        "`````````````````:BW@dhbddB@@,``````````````````^]W$@@$of@@@r````````````````````````",
        "`````````````````XMW0hWW@@@@c````````````````````\"xWWWWWJc@@$,```````````````````````",
        "````````````````lMW$zWW$@@@@``````````````````````~*WWWWWn@@$}```````````````````````",
        "```````````````^zMWf$WW@@@@<```````````````````````vBWWWWWJ$@b,``````````````````````",
        "```````````````,MW0mWW$@@@m,````````````````````````0WWWWW$d@k:``````````````````````",
        "```````````````-b@zWWW$@@@~``````````````````````````JM@@@@MMBz^`````````````````````",
        "`````````````^[#odh*hW@@m:```````````````````````````\"MWWd@W*@@n\"````````````````````",
        "````````````\"(MWQoW@@@@@-`````````````````````````````[MWWWWB#@@0:```````````````````",
        "```````````\"xWWC*W@@@@C````````````````````````````````;|$WWW@#@@p```````````````````",
        "``````````^<$Bb$W@@@$)```````````````````````````````````~pBWWB0B@l``````````````````",
        "``````````^[omWB@@$|``````````````````````````````````````:/hBBB@*{``````````````````",
        "``````````^<rzdQ/:```````````````````````````````````````````^l~1|\"``````````````````"
    };

    for (const auto& line : art) {
        cout<< "\033[38;5;214m" << line  << "\033[0m" << endl;
    }
    cout << "\n";
}


int main()
{
    
    art();
    while(true)

    {
            //ler a linha
       string prompt = "\033[1;38;5;63m" + filesystem::current_path().string() + "\033[0m" + "\033[1;38;5;214m <<GOKU_TERMINAL>>\033[0m ";
       char* input = readline(prompt.c_str());

        
        if(input == nullptr) {
            break;
        }

        string line(input);
        free(input);

        if(!line.empty()) {
            add_history(line.c_str());
        }

        

        if(line == "exit") {
            return 0;
        }

        if(line.empty()) {
            continue;
        }


        //agora começa o tratamento de dados, estamos tokenizando ou seja separando a string em varias outras strings
        istringstream ss(line);
        vector<string> tokens;
        vector<char*> argv;
        string token;

        while (ss >> token)
        {
            tokens.push_back(token);
        }
        
        if(tokens[0] == "cd") {
            
            if(tokens.size() < 2) {
                perror("falta argumento");
            }
            else {
                if(chdir(tokens[1].c_str()) != 0) {
                    perror("cd");
                }
            }

            continue;
        }

      /*  if(tokens[0] == "SERVER_START") {
            if(tokens.size() < 2) {
                perror("erro");
            }
            else {

                int porta = stoi(tokens[1]);
                pid_t server_pid = fork();

                if(server_pid == 0) {
                    server(porta);
                    exit(0);
                }
                else if (server_pid < 0)
                {
                    perror("fork");
                }
                else {
                    cout << "Servidor iniciador em background PID: " << server_pid << "\n";
                }
            }
            
            continue;
        }
        */        
        //agora precisamos decidir qual função vamos usar e porque (exec, excevp, execlp, etc ..) e depois tratar a entrada dos paramentros
        //escoli usar o execvp e descobri que sua entrada é um pnteiro para uma lista de argumentos
        
        for(int i = 0; i < tokens.size(); i++) {
            argv.push_back(const_cast<char*>(tokens[i].c_str()));
        }
        argv.push_back(nullptr);

        pid_t pid = fork();

        if(pid == 0) {
            execvp(argv[0],argv.data());
            perror("execvp");
            exit(1);
        }

        else {
            int status;
            waitpid(pid,&status,0);
            cout << "\n";
        }
        //agora tenho a minha entrada

        }

        //duvidas data

    return 0;
}