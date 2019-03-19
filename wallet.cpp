#include <bits/stdc++.h>
#include <ctime>
#include "wallet.h"
#include <stdlib.h>
bool is_sub_string(std::string a,std::string b)
{
    for(int i=0;i<b.size()-a.size();i++)
    {
        int j=0;
        for(;j<a.size();j++)
        {
            if(a[j]==b[i+j])
            {
                continue;
            }
            break;
        }
        if(j==a.size())
        {
            return true;
        }
        return false;
    }
}
std::vector<std::string> tokenizer(std::string str)
{
    std::vector<std::string> vs;
    std::string s = "";
    for(size_t i = 0; i < str.size(); i++)
    {
        if(str[i]==' ')
        {
            if(!s.empty())
            {
                vs.push_back(s);
            }
            s = "";
        }
        else
        {
            s += str[i];
        }
    }
    if(!s.empty())
    {
        vs.push_back(s);
    }
    return vs;
}
wallet::wallet(std::string file_name)
{
    valid_wallet = true;
    std::ifstream infile(file_name+".wallet");
    if(!infile.good())
    {
        valid_wallet = false;
        return;
    }
    wallet_file_name = file_name;
    std::string line;
    getline(infile,line);
    wallet_name = line;
    getline(infile,line);
    std::vector<std::string> tokens = tokenizer(line);
    no_of_transactions = stoi(tokens[0]);
    balance = stod(tokens[1]);
    history.resize(no_of_transactions);
    int i = 0;
    while(getline(infile,line))
    {
        //std::cout << line << "\n";
        std::vector<std::string> tokens = tokenizer(line);
        std::string str,str1,str2;
        getline(infile,str);
        getline(infile,str1);
        getline(infile,str2);
        //std::cout << history.size() << '\n';
        history[i] = {tokens[0],str,tokens[1],str1,str2,tokens[2]};
        //std::cout << tokens[2] << '\n';
        i++;
    }
    std::ofstream outfile,outfile1;
    outfile.open(file_name +".wallet.logs",ios::app);
    outfile1.open("universal.logs",ios::app);
    time_t curr_time;
	curr_time = time(NULL);
	char *tm = ctime(&curr_time);
    outfile << "Wallet accessed at time " << tm << '\n' ;
    outfile1 << "Wallet file : " << file_name << " accessed at time "  << tm << '\n';
    outfile.close();
    outfile1.close();
}
wallet::wallet(std::string file_name,std::string wall_name)
{
    std::ifstream checkfile(file_name+".wallet");
    if(checkfile.good())
    {
        valid_wallet = false;
        return;
    }
    valid_wallet = true;
    wallet_file_name = file_name;
    wallet_name = wall_name;
    no_of_transactions = 0;
    balance = 0;
    std::ofstream ofile;
    ofile.open(file_name+".wallet");
    ofile << wallet_name << '\n';
    ofile << 0 << ' ' << 0 << '\n';
    ofile.close();
    ofstream outerfile;
    outerfile.open("all_wallets.logs",ios::app);
    outerfile << wallet_file_name << '\n';
    outerfile.close();
    history.resize(0);
    std::ofstream outfile,outfile1;
    outfile.open(file_name +".wallet.logs",ios::app);
    outfile1.open("universal.logs",ios::app);
    time_t curr_time;
	curr_time = time(NULL);
	char *tm = ctime(&curr_time);
    outfile << "Wallet created at time " << tm << '\n' ;
    outfile1 << "Wallet file : " << file_name << " created at time "  << tm << '\n';
    outfile.close();
    outfile1.close();
    return;
}
void wallet::write_wallet()
{
    std::ofstream ofile;
    ofile.open(wallet_file_name + ".wallet");
    ofile << wallet_name << '\n';
    ofile << no_of_transactions << ' ' << balance << '\n';
    for(auto tpl : history)
    {
        ofile << tpl[0] << ' ' << tpl[2] <<  ' ' << tpl[5] << '\n';
        ofile << tpl[1] << '\n';
        ofile << tpl[4] << '\n';
        ofile << tpl[5] << '\n';
    }
    ofile.close();
    std::ofstream outfile,outfile1;
    outfile.open(wallet_file_name +".wallet.logs",ios::app);
    outfile1.open("universal.logs",ios::app);
    time_t curr_time;
	curr_time = time(NULL);
	char *tm = ctime(&curr_time);
    outfile << "Wallet overwritten at time : " << tm << '\n' ;
    outfile1 << "Wallet file : " << wallet_file_name << " Wallet overwritten at time " << tm << '\n' ;
    outfile.close();
    outfile1.close();
}
bool wallet::show_wallet()
{
    if(!valid_wallet)
    {
        return false;
    }
    std::cout << "\n\n\n\n\n\n\n\n\n\n\n";
    std::cout << "Wallet : " << wallet_name << '\n';
    std::cout << "Number of Transactions : " << no_of_transactions << '\n';
    std::cout << "Balance : " << balance << '\n';
    for (auto tpl : history)
    {
        std::cout << tpl[0] << ' ' << tpl[1] << ' ' << tpl[2] << ' ' << tpl[3] << ' ' << tpl[4] << ' ' << tpl[5] << '\n';
    }
    std::ofstream outfile,outfile1;
    outfile.open(wallet_file_name +".wallet.logs",ios::app);
    outfile1.open("universal.logs",ios::app);
    time_t curr_time;
	curr_time = time(NULL);
	char *tm = ctime(&curr_time);
    outfile << "Wallet shown at time " << tm << '\n' ;
    outfile1 << "Wallet file : " << wallet_file_name << " shown at time "  << tm << '\n';
    outfile.close();
    outfile1.close();
    return true;
}
bool wallet::show_wallet(int a, int b)
{
    if(!valid_wallet)
    {
        return false;
    }
    std::cout << "\n\n\n\n\n\n\n\n\n\n\n";
    std::cout << "Wallet : " << wallet_name << '\n';
    std::cout << "Number of Transactions : " << no_of_transactions << '\n';
    std::cout << "Balance : " << balance << '\n';
    for (auto tpl : history)
    {
        if(stoi(tpl[0]) < a || stoi(tpl[0]) > b)
        {
            continue;
        }
        std::cout << tpl[0] << ' ' << tpl[1] << ' ' << tpl[2] << ' ' << tpl[3] << ' ' << tpl[4] << ' ' << tpl[5] << '\n';
    }
    std::ofstream outfile,outfile1;
    outfile.open(wallet_file_name +".wallet.logs",ios::app);
    outfile1.open("universal.logs",ios::app);
    time_t curr_time;
	curr_time = time(NULL);
	char *tm = ctime(&curr_time);
    outfile << "Wallet shown conditional with S.nos " << a << " to " << b << " at time " << tm << '\n' ;
    outfile1 << "Wallet file : " << wallet_file_name << " shown conditionally with S.nos " << a << " to " << b << " at time " << tm << '\n' ;
    outfile.close();
    outfile1.close();
    return true;
}
bool wallet::search_wallet_exactly(int parameter, std::string str)
{
    std::cout << "\n\n\n\n\n\n\n\n\n\n\n";
    std::ofstream ofile;
    ofile.open("exact_search_result.txt");
    std::cout << "Wallet : " << wallet_name << '\n';
    ofile << "Wallet : " << wallet_name << '\n';
    std::cout << "Number of Transactions : " << no_of_transactions << '\n';
    ofile << "Number of Transactions : " << no_of_transactions << '\n';
    std::cout << "Balance : " << balance << '\n';
    ofile << "Balance : " << balance << '\n';
    if(parameter > 6 || parameter < 0)
    {
        return false;
    }
    for (auto tpl : history)
    {
        if(tpl[parameter] != str)
        {
            continue;
        }
        std::cout << tpl[0] << ' ' << tpl[1] << ' ' << tpl[2] << ' ' << tpl[3] << ' ' << tpl[4] << ' ' << tpl[5] << '\n';
        ofile << tpl[0] << ' ' << tpl[1] << ' ' << tpl[2] << ' ' << tpl[3] << ' ' << tpl[4] << ' ' << tpl[5] << '\n';
    }
    ofile.close();
    std::ofstream outfile,outfile1;
    outfile.open(wallet_file_name +".wallet.logs",ios::app);
    outfile1.open("universal.wallet.logs",ios::app);
    time_t curr_time;
	curr_time = time(NULL);
	char *tm = ctime(&curr_time);
    outfile << "Wallet searched exactly with parameter : " << parameter << " and pattern " << str << " at time " << tm << '\n' ;
    outfile1 << "Wallet file : " << wallet_file_name << " searched exactly with parameter : " << parameter << " and pattern " << str << " at time " << tm << '\n' ;
    outfile.close();
    outfile1.close();
    return true;
}
bool wallet::search_wallet_approx(int parameter, std::string str)//shows chronological transactions container str in the respective parameter
{
    std::cout << "\n\n\n\n\n\n\n\n\n\n\n";
    std::ofstream ofile;
    ofile.open("approx_search_result.txt");
    std::cout << "Wallet : " << wallet_name << '\n';
    ofile << "Wallet : " << wallet_name << '\n';
    std::cout << "Number of Transactions : " << no_of_transactions << '\n';
    ofile << "Number of Transactions : " << no_of_transactions << '\n';
    std::cout << "Balance : " << balance << '\n';
    ofile << "Balance : " << balance << '\n';
    if(parameter > 6 || parameter < 0)
    {
        return false;
    }
    for (auto tpl : history)
    {
        if(!is_sub_string(tpl[parameter],str))
        {
            continue;
        }
        std::cout << tpl[0] << ' ' << tpl[1] << ' ' << tpl[2] << ' ' << tpl[3] << ' ' << tpl[4] << ' ' << tpl[5] << '\n';
        ofile << tpl[0] << ' ' << tpl[1] << ' ' << tpl[2] << ' ' << tpl[3] << ' ' << tpl[4] << ' ' << tpl[5] << '\n';
    }
    ofile.close();
    std::ofstream outfile,outfile1;
    outfile.open(wallet_file_name +".wallet.logs",ios::app);
    outfile1.open("universal.logs",ios::app);
    time_t curr_time;
	curr_time = time(NULL);
	char *tm = ctime(&curr_time);
    outfile << "Wallet searched approximately with parameter : " << parameter << " and pattern " << str << " at time " << tm << '\n' ;
    outfile1 << "Wallet file : " << wallet_file_name << " searched approximately with parameter : " << parameter << " and pattern " << str << " at time " << tm << '\n' ;
    outfile.close();
    outfile1.close();
    return true;
}
bool wallet::sort_wallet(int parameter)
{
}
bool wallet::add_entry(std::vector<std::string> tp)
{
    if(!valid_wallet)
    {
        return false;
    }
    for(int i=0;i<tp.size();i++)
    {
        std::cout << tp[i] << ' ';
    }
    std::cout << '\n';
    tp[5] = to_string(stod(tp[2])+balance);
    no_of_transactions += 1;
    balance = stod(tp[5]); 
    history.push_back(tp);
    std::ofstream outfile,outfile1;
    outfile.open(wallet_file_name +".wallet.logs",ios::app);
    outfile1.open("universal.logs",ios::app);
    time_t curr_time;
	curr_time = time(NULL);
	char *tm = ctime(&curr_time);
    outfile << "Wallet entry : " << tp[0] << ' ' << tp[1] << ' ' << tp[2] << ' '<< tp[3] << ' ' << tp[4] << ' ' << tp[5] << ' '  << " added at time " << tm << '\n' ;
    outfile1 << "Wallet file : " << wallet_file_name << " Wallet entry : " << tp[0] << ' ' << tp[1] << ' ' << tp[2] << ' '<< tp[3] << ' ' << tp[4] << ' ' << tp[5] << ' '  << " added at time " << tm << '\n' ;
    outfile.close();
    outfile1.close();
    write_wallet();
    return true;
}
bool wallet::delete_entry(int s_no)
{
    if(s_no > history.size())
    {
        return false;
    }
    int i = 0;
    auto it = history[s_no-1];
    no_of_transactions -= 1;
    balance -= stod(it[5]);
    history.erase(history.begin()+s_no-1);
    for(int i=s_no-1;i<history.size();i++)
    {
        history[i][0] = to_string(stoi(history[i][0])-1);
    }
    std::ofstream outfile,outfile1;
    outfile.open(wallet_file_name +".wallet.logs",ios::app);
    outfile1.open("universal.logs",ios::app);
    time_t curr_time;
    curr_time = time(NULL);
    char *tm = ctime(&curr_time);
    outfile << "Wallet entry : with s.no. " << s_no << " deleted at time " << tm << '\n' ;
    outfile1 << "Wallet file : " << wallet_file_name << " Wallet entry : with s.no. " << s_no << " deleted at time " << tm << '\n' ;
    outfile.close();
    outfile1.close();
    write_wallet();
    return true;
}
int wallet::get_number_of_transactions()
{
    return no_of_transactions;
}
wallet::~wallet()
{
}