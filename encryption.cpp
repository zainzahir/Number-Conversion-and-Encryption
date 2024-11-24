#include<iostream>
using namespace std;
int power(int x, int y);
string decimalToBase(int num, int conversionBase);
int baseToDecimal(int num, int base);
int hexaToDecimal(string hexNum);
void numberConversionheader();
void mainHeader();
void encryptionHeader();
void numberConversionsystem(char choice,int &num,string &hexNum);
string encryption(string str);
string decimalToString(int num);
int main(){
    char choice;
    int num;
    string hexNum;
    do{
        mainHeader();
        cout<<encryption("Hi")<<endl;
        cout<<"\n\nSelect your desired option : ";
        cin>>choice;
        switch (choice){
            case '1':{ //Number Conversion system
                numberConversionsystem(choice,num,hexNum);
                break;
            }
            case '2':{ //Encryption & Decryption
                /* code */
                break;
            }
            case '0':{ //exit
                cout<<"Thank you, Exit successfully.";
                break;
            }
            default:
                cout<<"Invalid choice!";
                break;
        }
        
    }while(choice!='0');
    return 0;
}
//<---------------number conversion-------------------------->
void numberConversionsystem(char choice,int &num,string &hexNum){
    do{
        numberConversionheader();
        cout<<"Select the input number system : ";
        cin>>choice;
        switch(choice){
            case '1':{ //binary
                cout<<"Enter the number : ";
                cin>>num;
                num = baseToDecimal(num,2); //number is now in decimal
                cout<<"Decimal : "<<num<<endl;
                cout<<"Octal : "<<decimalToBase(num,8)<<endl;
                cout<<"Hexadecimal : "<<decimalToBase(num,16)<<endl;
                system("pause");
                break;
            }
            case '2':{ //octal
                cout<<"Enter the number : ";
                cin>>num;
                num = baseToDecimal(num,8); //number is now in decimal
                cout<<"Binary : "<<decimalToBase(num,2)<<endl;
                cout<<"Decimal : "<<num<<endl;
                cout<<"Hexadecimal : "<<decimalToBase(num,16)<<endl;
                system("pause");
                break;
            }
            case '3':{ //decimal
                cout<<"Enter the number : ";
                cin>>num;
                cout<<"Binary : "<<decimalToBase(num,2)<<endl;
                cout<<"Octal : "<<decimalToBase(num,8)<<endl;
                cout<<"Hexadecimal : "<<decimalToBase(num,16)<<endl;
                system("pause");
                break;
            }
            case '4':{ //hexadecimal
                cout<<"Enter the number : ";
                cin>>hexNum;
                num = hexaToDecimal(hexNum); //number is now in decimal
                cout<<"Binary : "<<decimalToBase(num,2)<<endl;
                cout<<"Octal : "<<decimalToBase(num,8)<<endl;
                cout<<"Decimal : "<<num<<endl;
                system("pause");
                break;
            }
            case '0':
                break;
            default:{
                cout<<"Invalid choice!"<<endl;
                system("pause");
            }
        }
    }while(choice!='0');
}
//<--------------------Encryption function-------------------->
string encryption(string str){
    string encryptStr = "";
    int ascii;
    for(int i=0; i<str.length(); i++){
        if(str[i]>='A' && str[i]<='Z'){
            ascii = str[i] - 'A'  + 65; //converts into decimal acsii
        }
        else if(str[i]>='a' && str[i]<='z'){
            ascii = str[i] - 'a'  + 97; //converts into decimal acsii
        }
        encryptStr += decimalToString(ascii) + " ";
    }
    return encryptStr;
}
string decimalToString(int num) {
    string result = "";
    while(num!=0){
        int lastDigit = num % 10; //extract last digit
        num = num / 10; //removes last digit
        result = static_cast<char>(lastDigit + '0') + result;
    }
    return result;
}
//<-----------------number system conversion-------------------------->
//decimal to bin, oct and hex
string decimalToBase(int num, int conversionBase){
    string result = "";
    int lastDigit = 0;
    int i = 1;
    if(num == 0) //if user enter 0
        return "0";
    while (num!=0){
        lastDigit = num % conversionBase;
        num = num / conversionBase;
        if(lastDigit<10){
            result = char(lastDigit + '0') + result;
        }
        else{
            result = char(lastDigit - 10 + 'A') + result;
        }
    }
    return result;
}
//any base to decimal except hex
int baseToDecimal(int num, int base){
    int result = 0, i = 0, lastDigit = 0;
    if(num == 0) //if user enter 0
        return 0;
    while(num!=0){
        lastDigit = num % 10;
        num = num / 10;
        result = result + lastDigit*power(base,i);
        i++;
    }
    return result;
}
int hexaToDecimal(string hexNum){
    int result = 0, lastDigit = 0;
    int toPower = 0;
    for(int i=hexNum.length()-1; i>=0; i--){
        if(hexNum[i]>='0' && hexNum[i]<='9'){
            lastDigit = hexNum[i] - '0';
            result += lastDigit*power(16,toPower);
            toPower++;
        }
        else if(hexNum[i]>='A' && hexNum[i]<='F'){
            lastDigit = hexNum[i] - 'A' + 10;
            result += lastDigit*power(16,toPower);
            toPower++;
        }
    }
    return result;
}
//calculate power
int power(int x, int y){
    int power = 1;
    for(int i=1; i<=y; i++){
        power *= x;
    }
    return power;
}

//<------------------------interfaces-------------------------->
void mainHeader(){
    system("cls");
    cout<<"************************************************"<<endl;
    cout<<"   ----- Number Conversion & Encryption -----   "<<endl;
    cout<<"************************************************"<<endl;
    cout<<"1. Number Conversion system"<<endl;
    cout<<"2. Encryption & Decryption"<<endl;
    cout<<"0. Exit"<<endl;
}
void numberConversionheader(){
    system("cls");
    cout<<"************************************************"<<endl;
    cout<<"     ------ Number Conversion system ------     "<<endl;
    cout<<"************************************************"<<endl;
    cout<<"1. Binary"<<endl;
    cout<<"2. Octal"<<endl;
    cout<<"3. Decimal"<<endl;
    cout<<"4. Hexadecimal"<<endl;
    cout<<"0. Exit"<<endl;
}
void encryptionHeader(){
    system("cls");
    cout<<"************************************************"<<endl;
    cout<<"     ------ Encryption & Decryption  ------     "<<endl;
    cout<<"************************************************"<<endl;
    cout<<"1. Encryption"<<endl;
    cout<<"2. Decryption"<<endl;
    cout<<"0. Exit"<<endl;
}