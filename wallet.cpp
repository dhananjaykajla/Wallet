#include <bits/stdc++.h>
#include <ctime>
#include "wallet.h"
#include <stdlib.h>
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
    std::ifstream infile(file_name);
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
        std::vector<std::string> tokens = tokenizer(line);
        std::string str,str1;
        getline(infile,str);
        getline(infile,str1);
        history[i] = make_tuple(stoi(tokens[0]),tokens[1],stod(tokens[2]),str,str1,stod(tokens[3]));
        i++;
    }
    std::ofstream outfile,outfile1;
    outfile.open(file_name +"_logs",ios::app);
    outfile1.open("universal_logs",ios::app);
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
    std::ifstream checkfile(file_name);
    if(checkfile.good())
    {
        valid_wallet = false;
        return;
    }
    valid_wallet = true;
    wallet_file_name = file_name;
    wallet_name = wall_name;
    std::ofstream ofile;
    ofile.open(file_name);
    ofile << wallet_name << '\n';
    ofile << 0 << ' ' << 0 << '\n';
    ofile.close();
    std::ofstream outfile,outfile1;
    outfile.open(file_name +"_logs",ios::app);
    outfile1.open("universal_logs",ios::app);
    time_t curr_time;
	curr_time = time(NULL);
	char *tm = ctime(&curr_time);
    outfile << "Wallet created at time " << tm << '\n' ;
    outfile1 << "Wallet file : " << file_name << " created at time "  << tm << '\n';
    outfile.close();
    outfile1.close();
    return;
}
bool wallet::add_entry(std::tuple <int, std::string, double, std::string, std::string, double> tp )
{
    history.push_back(tp);
    std::ofstream outfile,outfile1;
    outfile.open(wallet_file_name +"_logs",ios::app);
    outfile1.open("universal_logs",ios::app);
    time_t curr_time;
	curr_time = time(NULL);
	char *tm = ctime(&curr_time);
    outfile << "Wallet entry : " << get<0>(tp) << ' ' << get<1>(tp) << ' ' << get<2>(tp) << ' '<< get<3>(tp) << ' ' << get<4>(tp) << ' ' << get<5>(tp) << ' '  << " added at time " << tm << '\n' ;
    outfile << "Wallet file : " << wallet_file_name << " Wallet entry : " << get<0>(tp) << ' ' << get<1>(tp) << ' ' << get<2>(tp) << ' '<< get<3>(tp) << ' ' << get<4>(tp) << ' ' << get<5>(tp) << ' '  << " added at time " << tm << '\n' ;
    outfile.close();
    outfile1.close();
    return true;
}
bool wallet::show_wallet()
{
    if(!valid_wallet)
    {
        return;
    }
    std::cout << "\n\n\n\n\n\n\n\n\n\n\n";
    std::cout << "Wallet : " << wallet_name << '\n';
    std::cout << "Number of Transactions : " << no_of_transactions << '\n';
    std::cout << "Balance : " << balance << '\n';

    std::ofstream outfile,outfile1;
    outfile.open(wallet_file_name +"_logs",ios::app);
    outfile1.open("universal_logs",ios::app);
    time_t curr_time;
	curr_time = time(NULL);
	char *tm = ctime(&curr_time);
    outfile << "Wallet accessed at time " << tm << '\n' ;
    outfile1 << "Wallet file : " << file_name << " accessed at time "  << tm << '\n';
    outfile.close();
    outfile1.close();
}
wallet::~wallet()
{
}
