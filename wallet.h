#if !defined(WALLET_H)
#define WALLET_H
#include <bits/stdc++.h>
using namespace std;
class wallet
{
private:
    /* data */
    std::string wallet_file_name;
    std::string wallet_name;
    bool valid_wallet;
    double balance;
    int no_of_transactions;
    std::vector <std::tuple <int, std::string, double, std::string, std::string, double> > history;
public:
    wallet(std::string);//initializes pre_existing wallet
    wallet(std::string,std::string);//initializes new wallet
    bool show_wallet();//shows all the transactions
    bool show_wallet(int a, int b);//shows the entries from serial number a to serial number b
    bool search_wallet_exactly(int parameter,std::string str);//shows chronological transactions matching str exactly in the respective parameter
    bool search_wallet_approx(int parameter, std::string str);//shows chronological transactions container str in the respective parameter
    bool sort_wallet(int parameter);//sorts the wallet by the given parameter
    bool generate_wallet_file(std::string);//puts the wallet in an organised text file
    bool add_entry(std::tuple <int, std::string, double, std::string, std::string, double> );// adds an entry into the wallet
    bool delete_entry(int s_no, std::string file_name);//deletes the s_no'th entry from the wallet
    bool show_local_logs();//shows current wallet editing logs
    bool show_universal_logs();//shows universal wallet editing logs
    //void statistics();//To be implemented in future
    ~wallet();
};
#endif