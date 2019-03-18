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
    double balance;
    int no_of_transactions;
    std::vector<std::vector<std::string> > history;
public:
    bool valid_wallet;
    wallet(std::string);//initializes pre_existing wallet
    wallet(std::string,std::string);//initializes new wallet
    void write_wallet();
    bool show_wallet();//shows all the transactions
    bool show_wallet(int a, int b);//shows the entries from serial number a to serial number b
    bool search_wallet_exactly(int parameter,std::string str);//shows chronological transactions matching str exactly in the respective parameter
    bool search_wallet_approx(int parameter, std::string str);//shows chronological transactions container str in the respective parameter
    bool sort_wallet(int parameter);//sorts the wallet by the given parameter
    bool generate_wallet_file(std::string);//puts the wallet in an organised text file
    bool add_entry(std::vector<std::string>);// adds an entry into the wallet
    bool delete_entry(int s_no);//deletes the s_no'th entry from the wallet
    bool show_local_logs();//shows current wallet editing logs
    bool show_universal_logs();//shows universal wallet editing logs
    int get_number_of_transactions();
    //void statistics();//To be implemented in future
    ~wallet();
};
#endif