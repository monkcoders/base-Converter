#include<bits/stdc++.h>
#include<iostream>
using namespace std; 

char hexDigits[]={'0', '1' , '2', '3','4','5','6','7','8','9','A','B','C','D','E','F'};


string fromBinary(string n, int base){
    string ans="";
    int dec=0;
    

    switch (base)
    {
    case 8:
        for(int i=n.length()-1, oct=0,count=0; i>=0; i--){
            oct += int(n[i]-'0')*pow(2,count);
            count++;
            if(count==3 || i==0){
                ans = to_string(oct)+ ans;
                oct=0; count=0;
            }    
        }
        break;

    case 10: 
        for(int i=n.length()-1; i>=0; i--){
            dec+=int(n[i]-'0')*pow(2,n.length()-i-1);
        }
        ans = to_string(dec)+ans;
        break;

    case 16:
        for(int i=n.length()-1, hex=0,count=0; 
i>=0; i--){
            hex += int(n[i]-'0')*pow(2,count);
            count++;
            if(count==4 || i==0){
                ans = hexDigits[hex]+ ans;
                hex=0; count=0;
            }
        }
        break;
    default:
    break;
    }

    return ans;
}

string fromOctal(string num, int base){
    string ans="";
    int n = num.length();
    int currOct=0;
    switch (base)
    {
    case 2:
        for(int i=n-1; i>=0; i--){
            currOct = num[i]-'0';
            while(currOct>0){
                ans= to_string(currOct&1)+ans;
                currOct=currOct>>1; 
            }
        }
        break;
    case 10:
        for(int i=n-1; i>=0; i--){
            currOct += (num[i]-'0')*pow(8, n-i-1);
            
        }
        ans= to_string(currOct);
        break;
    
    case 16:
        ans = fromBinary(fromOctal(num,2),16);
        break;
    default:
    cout<<"Erorr: invalid base ";
        break;
    }
    return ans;
}



string fromDecimal(int n, int base){
    string ans="";
    switch (base)
    {
    case 2:
        while(n>0){
            ans= to_string(n&1)+ans;
            n=n>>1;
        }
        break;
    case 8:
        while (n>0)
        {
            ans = to_string(n%8)+ans;
            n=n/8;
        }
        
        break;
    case 16:
        while (n>0)
        {
            ans = hexDigits[n%16] +ans;
            n= n/16;   
        }
        break;
           
    default:
        cout<<"Error: base Does not exist!!!";
        break;
}
    return ans;

}

int getReminderForHex(char hexVal){
    if(hexVal>='A' && hexVal<='F') return 10 + hexVal-'A';
    return hexVal-'0';
}

string fromHexadecimal(string num, int base){
    int n=num.length();
    string ans="";
    int currDec=0;
    switch(base)
    {
    case 2:
        for(int i=n-1; i>=0; i--){
            int j= getReminderForHex(num[i]);
            int k=0;
            while (j>0 || k<4)
            {
                ans= to_string(j&1)+ ans;
                j= j>>1;
                k++;
            }
            
        }
        break;
    case 8:
        ans= fromBinary(fromHexadecimal(num,2),8);
        break;

    case 10:
        for(int i=n-1; i>=0; i--){
            currDec+= getReminderForHex(num[i])*pow(16,n-1-i);
        }
        ans = to_string(currDec);
        break;
    
    default:
        break;
    }
    return ans;
}

int main(){
    cout<<"It is a simp[le number system base conversion prom which can help you in conversion from/to Binary, Octal, Decimal, HexaDecimal "<<endl;
    int userInput=0;
    while (true)
    {
        
    
    cout<<"What type of conversion do you want to carry out: "<<endl;
    cout<<"1. Binary to Octal :"<<endl;
    cout<<"2. Binary to Decimal :"<<endl;
    cout<<"3. Binary to Hexadecimal :"<<endl;
    cout<<"4. Octal to Binary :"<<endl;
    cout<<"5. Octal to Decimal :"<<endl;
    cout<<"6. Octal to Hexadecimal :"<<endl;
    cout<<"7. Decimal to Binary :"<<endl;
    cout<<"8. Decimal to Octal :"<<endl;
    cout<<"9. Decimal to Hexadecimal :"<<endl;
    cout<<"10. Hexadecimal to Binary : "<<endl;
    cout<<"11. Hexadecimal to Octal : "<<endl;
    cout<<"12. Hexadecimal to Decimal : "<<endl;


    cin>>userInput;
    cout<<"Enter the number : ";
    int num;
    cin>>num;

    switch (userInput)
    {
    case 1:
        cout<<"Binary is : "<<num <<" Octal is : "<<fromBinary(to_string(num), 8)<<endl;
        break;
    case 2:
        cout<<"Binary is : "<<num <<" Decimal is : "<<fromBinary(to_string(num), 10)<<endl;
        break;

    case 3:
        cout<<"Binary is : "<<num <<" Hexadecimal is : "<<fromBinary(to_string(num), 16)<<endl;
        break;
    
    case 4:
        cout<<"Octal is : "<<num <<" Binary is : "<<fromOctal(to_string(num), 2)<<endl;
        break;
    case 5:
        cout<<"Octal is : "<<num <<" Decimal is : "<<fromOctal(to_string(num), 10)<<endl;
        break;
    case 6:
        cout<<"Octal is : "<<num <<" Hexadecimal is : "<<fromOctal(to_string(num), 16)<<endl;
        break;
    case 7:
        cout<<"Decimal is : "<<num <<" Binary is : "<<fromDecimal(num, 2)<<endl;
        break;
    case 8:
        cout<<"Decimal is : "<<num <<" Octal is : "<<fromDecimal(num, 8)<<endl;
        break;
    case 9:
        cout<<"Decimal is : "<<num <<" Hexadecimal is : "<<fromDecimal(num, 16)<<endl;
        break;
    case 10:
        cout<<"Hexadecimal is : "<<num <<" Binary is : "<<fromHexadecimal(to_string(num), 2)<<endl;
        break;
    case 11:
        cout<<"Hexadecimal is : "<<num <<" Octal is : "<<fromHexadecimal(to_string(num), 8)<<endl;
        break;
    case 12:
        cout<<"Hexadecimal is : "<<num <<" Decimal is : "<<fromHexadecimal(to_string(num), 10)<<endl;
        break;
    

    default:
        break;
    }

    
    

    }


   return 0;
}