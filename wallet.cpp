#include <bits/stdc++.h>
#include "wallet.h"
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
    std::ofstream outfile;
    outfile.open("")
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
    std::ofstream outfile;
    outfile.open(file_name);
    outfile << wallet_name << '\n';
    outfile << 0 << ' ' << 0 << '\n';
    outfile.close();
    return;
}
wallet::~wallet()
{
}
