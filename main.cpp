#include<bits/stdc++.h>
#include "wallet.h"
using namespace std;
int create_wallet()
{
    std::cout << "Enter the name of your wallet (without spaces)\n";
    std::string str;
    getline(cin,str);
    ifstream checkfile(str);
    if(checkfile.good())
    {
        std::cout << "Sorry a wallet of this name already exists\n";
        return 0; 
    }
    else
    {
        wallet new_wallet(str,str);
        if(new_wallet.valid_wallet)
        {
            std::cout << "Wallet created successfully\n";
        }
        else
        {
            std::cout << "Some Error occurred\n";
            return 0;
        }
    }
}
bool show_all_wallets()
{
    ifstream innerfile("all_wallets.logs");
    if(!innerfile.good())
    {
        return false;
    }
    std::string str;
    while(getline(innerfile,str))
    {
        std::cout << str << '\n';
    }
    innerfile.close();
    return true;
}
void existing_wallet()
{
    std::cout << "Enter the name of the wallet\n";
    std::string str;
    getline(cin,str);
    wallet old_wallet(str);
    if(!old_wallet.valid_wallet)
    {
        std::cout << "Wallet is not valid\n";
        return;
    }
    else
    {
        std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n Press : \n 0 : to show all transactions\n 1 : to show all transactions between two serial numbers\n 2 : to search the wallet exactly\n 3 : to search the wallet approximately\n 4 : to add entry to the wallet\n 5 : to delete the entry of the wallet\n anything else to go back to main menu\n";
        std::string choice;
        getline(cin,choice);
        if(choice == "0")
        {
            old_wallet.show_wallet();
            return;
        }
        else if(choice == "1")
        {
            std::cout << "Enter the two serial numbers : \n";
            int a,b;
            std::cin >> a >> b;
            cin.ignore();
            old_wallet.show_wallet(a,b);
        }
        else if(choice == "2")
        {
            std::cout << "Enter the parameter you want to search :\n 0 : to search for serial numbers \n 1 : to search for the recipient\n 2 : to search by transaction amount\n 3 : to search for date\n 4 : to search for remark\n 5 : to search for cumulative money at that pt in the wallet\n anything else : to return to main menu\n";
            std::string str;
            getline(cin,str);
            if(!(str == "0" || str == "1" || str == "2" || str == "3" || str == "4" || str == "5"))
            {
                return;
            } 
            int param = stoi(str);
            std::cout << "Enter the keyword\n";
            getline(cin,str);
            old_wallet.search_wallet_exactly(param,str);
        }
        else if(choice == "3")
        {
            std::cout << "Enter the parameter you want to search :\n 0 : to search for serial numbers \n 1 : to search for the recipient\n 2 : to search by transaction amount\n 3 : to search for date\n 4 : to search for remark\n 5 : to search for cumulative money at that pt in the wallet\n anything else : to return to main menu\n";
            std::string str;
            getline(cin,str);
            if(!(str == "0" || str == "1" || str == "2" || str == "3" || str == "4" || str == "5"))
            {
                return;
            } 
            int param = stoi(str);
            std::cout << "Enter the keyword\n";
            getline(cin,str);
            old_wallet.search_wallet_approx(param,str);
        }
        else if(choice == "4")
        {
            std::vector<std::string> vs;
            int sno = old_wallet.get_number_of_transactions()+1;
            vs.push_back(to_string(sno));
            std::cout << "Enter the name of the recipient/donor \n";
            std::string a;
            getline(cin,a);
            vs.push_back(a);
            std::cout << "Enter the amount +ve for recieved money, -ve for money given out \n";
            double d;
            std::cin >> d;
            cin.ignore();
            vs.push_back(to_string(d));
            std::cout << "Enter the date or -1 to use the present time \n";
            std::string date;
            getline(cin,date);
            if(date == "-1")
            {
                time_t curr_time;
	            curr_time = time(NULL);
	            char *tm = ctime(&curr_time);
                date = tm;
                date.pop_back();
            }
            vs.push_back(date);
            std::cout << "Please enter a remark on the transaction\n";
            std::string remark;
            getline(cin,remark);
            vs.push_back(remark);
            vs.push_back("0");
            old_wallet.add_entry(vs);
        }
        else if(choice == "5")
        {   
            std::cout << "Enter serial number of the entry to be removed or -1 to abort\n";
            int x;
            std::cin >> x;
            cin.ignore();
            if(x==-1)
            {
                return;
            } 
            else
            {
                old_wallet.delete_entry(x);
            }
        }   
        else
        {
            return;
        }
        
    }
    
}
void intro()
{
    std::string str = "0";
    while(str == "0" || str == "1" || str == "2")
    {
        std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n";/* code */
        std::cout << "Welcome to the wallet\n\n\n\n\n\n\n";
        std::string line;
        getline(cin,line);
        std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n";
        std::cout << "Press :\n 0 : To create a new wallet\n 1 : to list all your wallets\n 2 : to edit/show a particular wallet\n anything else to exit\n";
        std::string str;
        getline(cin,str);
        if(str == "0")
        {
            create_wallet();
            getline(cin,line);
        }
        else if(str == "1")
        {
            if(show_all_wallets())
            {
                getline(cin,line);
                continue;
            }
            else
            {
                std::cout << "There are no wallets\n";
                getline(cin,line);
                continue;
            }
            
        }
        else if(str == "2")
        {
            existing_wallet();
            getline(cin,line);
        }
        else
        {
            return ;
        }
    }
}
int main()
{
    intro();
    return 0;
}