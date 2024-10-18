// Amber's bakery order system
//fundamentals of programming assignment

#include<iostream>
#include<fstream>
#include<string>
#include<vector>

using namespace std;

string *SplitString(string wrd){
    //split a string by '/'
    //add "*" because it returns an array
    //add static it is returning array
    static string WordSet[5];
    string gh;
    int d = 0;

    for (int i = 0; i < wrd.length() ; i++) {
        if( wrd[i] != '/')  gh += wrd[i]; 
        else {
            WordSet[d] = gh;
            d++;
            gh = "";  
        }
    }
    WordSet[d] = gh;
    return WordSet;
}

string time(){
    //output time in numbers

    string time = __TIME__;
    string tme = time.substr(0, 2) + time.substr(3, 5) + time.substr(8, 10);  
    return tme.substr(0, 4) + "" + tme.substr(5, 7);
}

string date(){
    //output date yyyy/mm/dd

    string dte = __DATE__;
    //year
    string yy = dte.substr( dte.length() - 4,dte.length() - 1 );

    //date
    string h = dte.substr( dte.length() - 7, dte.length() - 9);
    int d = stoi(h);
    string dd;
    if(d > 9) dd = to_string(d);
    else dd = "0" + to_string(d);
    
    //month
    string tmp = dte.substr(0, 3);
    string mm;
    if (tmp == "Jan") mm = "01";
    else if (tmp == "Feb") mm = "02";
    else if (tmp == "Mar") mm = "03";
    else if (tmp == "Apr") mm = "04";
    else if (tmp == "May") mm = "05";
    else if (tmp == "Jun") mm = "06";
    else if (tmp == "Jul") mm = "07";
    else if (tmp == "Aug") mm = "08";
    else if (tmp == "Sep") mm = "09";
    else if (tmp == "Oct") mm = "10";
    else if (tmp == "Nov") mm = "11";
    else mm = "12";

    return yy +""+ mm +""+ dd;
}

string FloatToString(float j){
    string h = to_string(j);
    if (j > 1000) return h.substr(0, 7);
    else if (j > 100) return h.substr(0, 6);
    else if (j > 10) return h.substr(0, 5);
    else if (j > 0) return h.substr(0, 4);
    else return h.substr(0, 3);
}

struct Users {
    //keeps user data
    std::vector<string> id;
    std::vector<string> name;
    std::vector<string> username;
    std::vector<string> pasword;
    std::vector<string> phno;
    int n = 0;
};

struct LUser {
    //keep logged user data
    string id;
    string name;
    string username;
    string phno;
    string type;
};

struct items{
    //keep available items data
    std::vector<string> names;
    std::vector<float> prices;
    int n = 0;
};

struct bill{
    //keeps bill data

    string bill_id;
    string cus_name;
    string cus_id;
    int n = 0;//number of items
    float blltot = 0; //bill total
    std::vector<string> items; // bought items' names
    std::vector<int> num; // number of specific items
    std::vector<float> prices; // specific unit prices
    std::vector<float> tprcs; // total specific for item
 
    int dspy() {
        //to display bill after transaction

        if(num.size() == 0) return 0;
        cout<<"Customer ID : "<<cus_id<<endl;
        cout<<"Name : "<<cus_name<<endl;
        cout<<"Bill ID : "<<bill_id<<endl;
        cout<<"Date: "<<__DATE__<<endl;
        cout<<"Time: "<<__TIME__<<"\n"<<endl;

        string kl = "................................";
        for (int i = 0; i < items.size() ; i++) {
            cout<<i + 1<<") "<<items[i];
            cout<<kl.substr(0, kl.length() - items[i].length());
            cout<<num[i]<<" x "<< FloatToString(prices[i]);
            cout<<kl.substr(0, kl.length() - ( FloatToString(prices[i]).length() + FloatToString(tprcs[i]).length() ));
            cout<< FloatToString(tprcs[i])<<endl;
        }
        cout<<"\nFinal Total :    "<<blltot<<" /= Euros"<<endl;
        cout<<"\nBye "<<cus_name<<endl;
        return 1;
    }

    int prnt() {
        //tp save bill after transaction
        ofstream fle("./Orders/" + bill_id + ".txt");

        fle<<"Customer ID : "<<cus_id<<endl;
        fle<<"Name : "<<cus_name<<endl;
        fle<<"Bill ID : "<<bill_id<<endl;
        fle<<"Date: "<<__DATE__<<endl;
        fle<<"Time: "<<__TIME__<<"\n"<<endl;

        string kl = "................................";
        for (int i = 0; i < items.size() ; i++) {
            fle<<i + 1<<") "<<items[i];
            fle<<kl.substr(0, kl.length() - items[i].length());
            fle<<num[i]<<" x "<< FloatToString(prices[i]);
            fle<<kl.substr(0, kl.length() - ( FloatToString(prices[i]).length() + FloatToString(tprcs[i]).length() ));
            fle<< FloatToString(tprcs[i])<<endl;
        }
        fle<<"\nFinal Total :    "<<blltot<<" /= Euros"<<endl;

        fle.close();
        return 0;
    }
};

//global variables used in the programme
Users admins;
Users customers;
LUser loggedUser;
items baverage;
items bread;
items cackes;
items cockie;
items dessert;

void FillSets(Users &data, string fname){
    //modify users objects
    //adding "&" because it makes changes to original struct object
    
    string *k;
    ifstream fle(fname);
    string line;
    while( getline(fle, line) ){

        k = SplitString(line);
        data.id.push_back(k[0]);
        data.name.push_back(k[1]);
        data.username.push_back(k[2]);
        data.pasword.push_back(k[3]);
        data.phno.push_back(k[4]);
        data.n++;
    }
    fle.close();
}

void FillItems(items &data, string fname){
    //modify items objects

    string *k;
    ifstream fle(fname);
    string line;
    while( getline(fle, line) ){

       k = SplitString(line);
       data.names.push_back(k[0]);
       data.prices.push_back(stof(k[1]));
       data.n++;    
    }
    fle.close();
}

int scanObj(string usnme, string psw, Users data){
    //scan users objects

    for (int i = 0; i < data.n; i++) {
        if(usnme == data.username[i]){
            if(psw != data.pasword[i]){
                return -1;
            } else {
                return i + 1;
            }
        }
    }
    return 0;
}

int authenticate(string usnme, string psw){
    //find user in customer or admin objects

    int e = scanObj(usnme, psw, customers);
    int r = scanObj(usnme, psw, admins);
    if( e == -1 || r == -1 ) {
        return -1;
    }
    if(r) return r + customers.n + 1;
    if(e) return e;
    return 0; 
}

void login(int s, string type, Users data){
    //login user
    loggedUser.id = data.id[s];
    loggedUser.name = data.name[s];
    loggedUser.username = data.username[s];
    loggedUser.phno = data.phno[s];
    loggedUser.type = type;
}

void logout(){
    //logout current user
    loggedUser.id = "";
    loggedUser.name = "";
    loggedUser.phno = "";
    loggedUser.username = "";
    loggedUser.type = "";
}

void displayItems(bill &dta ,items data, string nme ,string label = "Price is for 1 in Euros\n"){
    //display items and  prices
    //add purchased items to bill
    
    string k = "...........................................";
    cout<<nme<<endl;
    cout<<"---------------------------------------"<<endl;
    cout<<label<<endl;

    for(int n = 0; n < data.n; n++){
        cout<<n + 1<<") ";
        cout<<data.names[n];
        string j = FloatToString(data.prices[n]);
        cout<<k.substr(0, (k.length() - data.names[n].length()));
        cout<<j<<endl;
    }
    cout<<"\nTo purchases type item no, minimum number of items is 1, to get to a another category give 'esc'"<<endl;

    int amm;
    string inpt;
    while(true) {
        cout<<"\nType item no : ";
        cin>>inpt;
        if(inpt == "esc") break;
        try{
            int y = stoi(inpt);
            if(y <= data.n ){
                cout<<"Ammount : ";
                cin>>amm;

                //update bill
                dta.n += amm;
                dta.items.push_back(data.names[y-1]);
                dta.prices.push_back(data.prices[y-1]);
                dta.tprcs.push_back(amm * data.prices[y-1]);
                dta.num.push_back(amm);
                dta.blltot += (amm * data.prices[y-1]);

                cout<<"\nCurrent Total : " <<dta.blltot <<"/= Euros"<<endl;
            } else cout<<"Invalid input...";

        } catch (const std::exception& e){
            cout<<"Error Invalid Input...";
        }
    }
}

void CustomerInterface() {
    //create bill according to customer input

    string inpt;
    bill cusbll;
    cusbll.cus_name = loggedUser.name;
    cusbll.cus_id = loggedUser.id; 

    cout<<"\nHello "<<loggedUser.name<<",\n";
    cout<<"\n..........................Amber Bakery (London, England)..........................\n";
    cout<<"Contact No : 2300 300 400\n";
    while (true) {
        cout<<"\nItem categories\n1 - Beverages \n2 - Breads \n3 - Cakes \n4 - Cookies \n5 - Desserts \n";
        cout<<"To logout give 'esc' To view items in a category press a number \n";
        cout<<"\nType Category : ";
        cin>>inpt;
        if(inpt == "esc") break;
        try{
            int gh = stoi(inpt);
            if(gh == 1) displayItems(cusbll, baverage, "\nBeverage");
            else if(gh == 2) displayItems(cusbll, bread, "\nBread");
            else if(gh == 3) displayItems(cusbll, cackes, "\nCake", "Price is for 500g peace\n");
            else if(gh == 4) displayItems(cusbll, cockie, "\nCookie");
            else if(gh == 5) displayItems(cusbll, dessert, "\nDessert");
            else cout<<"invalid input";
        } 
        catch (const std::exception& e) {
            cout<<"Error invalid input";
        };
    }
    cusbll.bill_id = "Bll" + date() + time();
    cusbll.dspy();
    cusbll.prnt();
    logout();
}

int main() {
    //getting users data
    FillSets(admins, "./Users/Admins.txt");
    FillSets(customers, "./Users/Customers.txt");

    //getitem items data
    FillItems(baverage, "./Items/Beverages.txt");
    FillItems(bread, "./Items/Breads.txt");
    FillItems(cackes, "./Items/Cackes.txt");
    FillItems(cockie, "./Items/Cockies.txt");
    FillItems(dessert, "./Items/Desserts.txt");    

    string usnme, psw;
    int p;
    int tryes = 0;//number of failed attempts
    while(true){

        //get username and password
        cout<<"\n\n---------------Amber's bakery User Login---------------" ;
        cout<<"\nUsername : ";
        cin>>usnme;
        if( usnme == "q" ) break;
        cout<<"Password : ";
        cin>>psw;

        //Authenticate user
        p = authenticate(usnme, psw);
        
        //check for unauthorized access
        if(p == 0 || p == -1){
            if(p == 0) cout<<"Wrong Username !!!"<<"\n";
            else if(p == -1) cout<<"Wrong Password !!!"<<"\n";
            tryes++;
                if( tryes == 3 ) {
                    cout<<"\nUnauthorized Access Detected \nEnter Administrator key to restart\n";
                    string ky = "";
                    while( ky != "admin0999" ){
                        cout<<"Enter Key : ";
                        cin>>ky;
                    }
                    cout<<"System restored...."<<endl;
                    tryes = 0;
            }
            continue;
        }

        if(p <= customers.n) login(p - 1, "Cus", customers);
        else login(p - (customers.n + 2), "Adm", admins);

        if( loggedUser.type == "Cus" ) {
            CustomerInterface();
            continue;
        } else {
            //Admin interface
            int hj;
            cout<<"Hello "<<loggedUser.name<<",\n";
            cout<<"Menu\n\n1 - To cose for the day\n2 - Add new customer \n\nType : ";
            cin>>hj;

            if(hj == 1){
                cout<<"\n"<<__DATE__<<" "<<__TIME__<<endl;
                cout<<"System close..............."<<endl;
                break;
            };
        
        }

        return 0;
    }
}
