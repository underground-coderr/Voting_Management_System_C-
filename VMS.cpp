//-------admin key is gas
#include<iostream>
#include <string>
#include<fstream>
using namespace std;
static int i = 0;
static int n;
static int party_1_counter=0, party_2_counter=0, party_3_counter=0, party_4_counter=0,party_5_counter;
int party_1_indicator=0, party_2_indicator=0 , party_3_indicator =0, party_4_indicator=0,party_5_indicator;

class info
{
protected:
    static string candidates[25];
    int voter_id[50];
    string voter_name[50];
    string voter_surname[50];
    
    string voter_password[50];
    int voter_check[50];
    static int votecount[25];
};

string info::candidates[25];
int info::votecount[25];

class interface
{
protected:
    void votingboard()
    {
        cout << "\n\t\t\t#################################################";
        cout << "\n\t\t\t#            ONLINE VOTING SYSTEM               #";
        cout << "\n\t\t\t#                 PROJECT                       #";
        cout << "\n\t\t\t#################################################";
        cout << "\n";
        cout << "\n\t\t\t#################################################";
        cout << "\n\t\t\t#         WELCOME TO ELECTIONS - 2023           #";
        cout << "\n\t\t\t#################################################";
        cout << "\n";
    }

   
};

class voter :protected info, virtual public interface
{
protected:
    void check_required();
    void voter_registration();
};
void voter::check_required()
{
    int noo = 0;
    for (noo = 0; noo < n; noo++)
    {
        voter_check[noo] = 0;
    }
    getc;
}
void voter::voter_registration()
{
    ofstream outfile("voters.txt", ios::app | ios::binary);

    system("cls");
    votingboard();
    static int x = 0;
    static int id = 3458889;
    if (!outfile.is_open()) {
        cerr << "Error: Unable to open file VOTERS.txt  for writing." << endl;
        return;
    }
    check_required();
    cout << "\n\t\t Your voter id is " << id;
    cout << "\n\t\t Please enter the voter id alloted to you: ";
    cin >> voter_id[i];
    outfile << voter_id[i] << "\t\t";
    cout << "\n\t\t Enter your first name: ";
    cin >> voter_name[i];
    outfile << voter_name[i] << " ";
    cout << "\n\t\t Enter your last name: ";
    cin >> voter_surname[i];
    outfile << voter_surname[i] << "\t\t";
    cout << "\n\t\t Enter your password: ";
    cin >> voter_password[i];
    outfile << voter_password[i] << endl;
    cout << "\n\t\t You have successfully completed the registration!!!";
    outfile.close();
    cout << "Names written to VOTERS.txt successfully." << endl;
    voter_check[i] = 1;
    i++;
    id++;

    fflush(stdin);
    getchar();
    system("cls");
}
class vote :protected voter
{
protected:
    void voter_login();
    void cast_vote();
    
};

class officer :protected info, virtual public interface
{
private:
    string vigilance_password = "gas";
    string entered_password = "";
protected:
    void vote_count();
    void vigilance_officer();
    void candi_entry();

};

class menu :protected vote, protected officer
{
public:
    void main_menu();
};
void vote::voter_login()
{
    //system("cls");
    int choice_voter;
    do
    {
        //system("cls");
        votingboard();
        cout << "\n\t\t\t################################################";
        cout << "\n\t\t\t#                  VOTER MENU                  #";
        cout << "\n\t\t\t################################################";
        cout << "\n";
        cout << "\n\t\t If you are a new voter please register yourself first by selecting choice 2";
        cout << "\n\t\t 1. Cast your vote";
        cout << "\n\t\t 2. Voter registration";
        cout << "\n\t\t 3. Back";
        cout << "\n\t\t Please enter your choice:";
        cin >> choice_voter;

        switch (choice_voter)
        {
        case 1: cast_vote(); break;
        case 2: voter_registration(); break;
        case 3: system("cls"); break;
        default: cout << "\n Kindly give a valid Input!";
        }
    } while (choice_voter != 3);
    fflush(stdin);
}

void vote::cast_vote()
{
    system("cls");
    votingboard();
    int choice;
    int x;
    int var1 = 0, var2 = 0;
    int var3 = 0;
    string passwerd;
    cout << "\n\t\t Enter your voter id : ";
    cin >> x;
    for (var1 = 0, var2 = 0; var1 < i || var2 <= i; var1++, var2++)
    {
        if (x == voter_id[var1])
        {
            do
            {
                cout << "\n\t\t Enter your password: ";
                cin >> passwerd;
                if (voter_password[var1] == passwerd)
                {
                    if (n != 0)
                    {
                        if (voter_check[var1] == 1)
                        {
                            cout << "\n\t\t Voter first name : " << voter_name[var1];
                            cout << "\n\t\t Voter last name : " << voter_surname[var1];
                            cout << "\n\n\t\t ### Please choose your Candidate ####";
                            for (int i = 0; i < n; i++)
                            {
                                cout << "\n\t\t" << i + 1 << ". " << candidates[i];
                            }
                            cout << "\n\n\t\t Input your choice (1 - " << n << " ) : ";
                            cin >> choice;
                            if (choice == 1) {
                                party_1_counter++;
                          
                            }
                            else if (choice == 2) {
                                party_2_counter++;
                            }
                            else if (choice == 3) {
                                party_3_counter++;
                            }
                            else if(choice == 4){
                                party_4_counter++;
                            }
                            else if (choice == 5) {
                                party_5_counter++;
                            }
                            
                            votecount[choice - 1]++;
                            voter_check[var2]++;
                        }
                        else
                        {
                            cout << "\n\t\t Sorry you have already voted!!!";
                        }
                        var3 = 0;
                    }
                    else
                    {
                        cout << "\n\t\tCandidates are not updated, voting not allowed! Contact Vigilante officer!";
                        exit(0);
                    }
                }
                else
                {
                    cout << "\n\t\tYou have entered the password incorrectly!!!";
                    cout << "\n\t\t Please re-enter the password correctly.....";
                    var3++;
                    break;
                }
            } while (var3 != 0 && var3 <= 3);
            break;
        }
        if (var2 == i)
        {
            cout << "\n\t\t Sorry the voter id does not exist!!!";
            break;
        }
    }
    cout << "\n\t\tThank you for your Participation!";
    fflush(stdin);
    getchar();
    system("cls");
}

void officer::vote_count()
{
    system("cls");
    votingboard();
    cout << "\n\t\t ##### Voting Statics ####";
    for (int i = 0; i < n; i++)
    {
        cout << "\n\t\t" << candidates[i] << "                " << votecount[i];
    }
    fflush(stdin);
    getchar();
    system("cls");
}

void officer::vigilance_officer()
{
    //system("cls");
    votingboard();
    char ch;
    cout << "\n\t\t ADMIN KEY : ";
    cin >> entered_password;

    system("cls");
    if (vigilance_password == entered_password)
    {
        int choice_officer = 0;
        do
        {
            //system("cls");
            votingboard();
            cout << "\n\t\t\t#################################################";
            cout << "\n\t\t\t#           OFFICER MENU                        #";
            cout << "\n\t\t\t#################################################";
            cout << "\n";
            cout << "\n\t\t 1. Find Vote Count";
            cout << "\n\t\t 2. Enter Candidates";
            cout << "\n\t\t 3. Back";

            cout << "\n\t\t Please enter your choice : ";
            cin >> choice_officer;

            switch (choice_officer)
            {
            case 1: vote_count(); break;
            case 2: candi_entry(); break;
            case 3: system("cls"); break;
            default: cout << "\n Kindly give a valid Input!";
            }
        } while (choice_officer != 3);
    }
    else
    {
        //system("cls");
        cout << "\n\t\t Please renter the password correctly";
    }
    fflush(stdin);
}

void officer::candi_entry()
{
    system("cls");
    votingboard();
    fstream f("PARTY_NAMES.txt", ios::app | ios::binary);
    int n1, p;
    cout << "\n\t\tEnter Number of Parties:";
    cin >> n1;
    if (n1 == 1) {
        party_1_indicator = 1;
    }
    else if (n1 == 2) {
        party_1_indicator = 1;
        party_2_indicator = 1;
    }
    else if (n1 == 3) {
        party_1_indicator = 1;
        party_2_indicator = 1;
        party_3_indicator = 1;
    }
    else if (n == 4) {
        party_1_indicator = 1;
        party_2_indicator = 1;
        party_3_indicator = 1;
        party_4_indicator = 1;
    }
    else if (n == 5) {
        party_1_indicator = 1;
        party_2_indicator = 1;
        party_3_indicator = 1;
        party_4_indicator = 1;
        party_5_indicator = 1;
    }
    n = n + n1;

    if (!f.is_open()) {
        cerr << "Error: Unable to open file VOTERS.txt  for writing." << endl;
        return;
    }
    for (p = i; p < n; p++)
    {
        cout << "\n\t\tParty " << p + 1 << " name :";
        cin >> candidates[p];
        f << candidates[p] << endl;
    }
    cout << "\n\t\tParties Updated Successfully!\n";
    f.close();
    cout << "Names written to BAN_VOTERS.txt successfully." << endl;
    i = p;
    fflush(stdin);
    getchar();
    system("cls");
}

void menu::main_menu()
{
    //system("cls");

    int i;
    int choice;

    while (1)
    {
        votingboard();
        cout << "\n\t\t\t##################################################";
        cout << "\n\t\t\t#                     LOGIN                      #";
        cout << "\n\t\t\t#------------------------------------------------#";
        cout << "\n\t\t\t#                   1. ADMIN                     #";
        cout << "\n\t\t\t#                   2. VOTER                     #";
        cout << "\n\t\t\t#                   3. EXIT                      #";
        cout << "\n\t\t\t##################################################";
        cout << "\n\t\t\tPlease enter your choice : ";
        cin >> choice;
        switch (choice)
        {
        case 1: system("cls"); vigilance_officer(); break;
        case 2: system("cls"); voter_login(); break;
        case 3: cout << "\n Session ended\n\n" ; break;
        default: system("cls");
            cout << " Kindly give a valid Input!\n "; break;
        }
        if (choice == 3) {
            break;
        }
    }
    //checkPartyCounter();

    fflush(stdin);
    getchar();
}
class Filing : public info{
    int maxValue, indexCount;
    int indices[5];
public:
    void checkPartyCounter() {
  

            ofstream outFile("RESULT.txt");
            if (!outFile.is_open()) {
                cerr << "Error: Unable to open file PARTY_1_COUNT.txt  for writing." << endl;
                return;
            }
            else {
                if (party_1_indicator == 1 && party_2_indicator == 0 && party_3_indicator == 0 && party_4_indicator == 0 && party_5_indicator == 0) {
                    outFile << "THE TOTAL VOTE COUNT OF PARTY_1 [" << candidates[0]<< "] is : " << party_1_counter << endl;
                    outFile.close();
                }
                else if (party_1_indicator == 1 && party_2_indicator == 1 && party_3_indicator == 0 && party_4_indicator == 0 && party_5_indicator == 0) {
                    outFile << "THE TOTAL VOTE COUNT OF PARTY_1 [" << candidates[0] << "] is : " << party_1_counter << endl;
                    outFile << "THE TOTAL VOTE COUNT OF PARTY_2 [" << candidates[1] << "] is : " << party_2_counter << endl;
                    outFile.close();

                }
                else if (party_1_indicator == 1 && party_2_indicator == 1 && party_3_indicator == 1 && party_4_indicator == 0 && party_5_indicator == 0) {
                    outFile << "THE TOTAL VOTE COUNT OF PARTY_1 [" << candidates[0] << "] is : " << party_1_counter << endl;
                    outFile << "THE TOTAL VOTE COUNT OF PARTY_2 [" << candidates[1] << "] is : " << party_2_counter << endl;
                    outFile << "THE TOTAL VOTE COUNT OF PARTY_3 [" << candidates[2] << "] is : " << party_3_counter << endl;
                    outFile.close();
                }
                else if (party_1_indicator == 1 && party_2_indicator ==1 && party_3_indicator == 1 && party_4_indicator == 1 && party_5_indicator == 0) {
                    outFile << "THE TOTAL VOTE COUNT OF PARTY_1 [" << candidates[0] << "] is : " << party_1_counter << endl;
                    outFile << "THE TOTAL VOTE COUNT OF PARTY_2 [" << candidates[1] << "] is : " << party_2_counter << endl;
                    outFile << "THE TOTAL VOTE COUNT OF PARTY_3 [" << candidates[2] << "] is : " << party_3_counter << endl;
                    outFile << "THE TOTAL VOTE COUNT OF PARTY_4 [" << candidates[3] << "] is : " << party_4_counter << endl;
                    outFile.close();
                }
                else if (party_1_indicator == 1 && party_2_indicator == 1 && party_3_indicator == 1 && party_4_indicator == 1 && party_5_indicator == 1) {
                    outFile << "THE TOTAL VOTE COUNT OF PARTY_1 [" << candidates[0] << "] is : " << party_1_counter << endl;
                    outFile << "THE TOTAL VOTE COUNT OF PARTY_2 [" << candidates[1] << "] is : " << party_2_counter << endl;
                    outFile << "THE TOTAL VOTE COUNT OF PARTY_3 [" << candidates[2] << "] is : " << party_3_counter << endl;
                    outFile << "THE TOTAL VOTE COUNT OF PARTY_4 [" << candidates[3] << "] is : " << party_4_counter << endl;
                    outFile << "THE TOTAL VOTE COUNT OF PARTY_5 [" << candidates[4] << "] is : " << party_5_counter << endl;
                    outFile.close();
                }
                else {
                    outFile << "NO CANDIDATES EXISTED !!! " << endl;
                    outFile.close();
                }
                    
            }
           
     }
        
    void Winner() {
        if (party_1_indicator == 0 && party_2_indicator == 0 && party_3_indicator == 0 && party_4_indicator == 0 && party_5_indicator == 0) {
            system("cls");
			cout << "NO VOTE CASTING EXISTED , HENCE NO WINNER ANNOUNCED !!!" << endl;
        }
        else
        {
            int winner[5] = { party_1_counter ,party_2_counter ,party_3_counter ,party_4_counter ,party_5_counter };
         
            int maxVotes = winner[0];
            for (int i = 1; i < 5; ++i) {
                if (winner[i] > maxVotes) {
                    maxVotes = winner[i];
                }
            }
            int maxIndices[5];
            int maxCount = 0;
            for (int i = 0; i < 5; ++i) {
                if (winner[i] == maxVotes) {
                    maxIndices[maxCount] = i + 1;  
                    maxCount++;
                }
            }
            if (maxCount == 1) {
                std::cout << "Party " << maxIndices[0] << " is the winner with " << maxVotes << " votes." << std::endl;
            }
            else {
                std::cout << "There is a tie between parties ";
                for (int i = 0; i < maxCount; ++i) {
                    std::cout << maxIndices[i];
                    if (i < maxCount - 1) {
                        std::cout << ", ";
                    }
                }
                std::cout << " with " << maxVotes << " votes each." << std::endl;
            }


        }

    }
     
    
};


int main()
{
    menu m;
    m.main_menu();
    Filing f;
    f.checkPartyCounter();
    f.Winner();
  
    return 0;
}



