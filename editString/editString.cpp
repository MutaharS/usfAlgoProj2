// Test comment

#define MAXLEN 20
#define MATCH 0
#define INSERT 1
#define DELETE 2

#include<string.h>
#include<string>
#include<iostream>

using namespace std;

int m[MAXLEN+1][MAXLEN+1]; // dynamic programming table 

void insert_out(string& t, int j)
{
    cout << "I";
}

void match_out(string& s, string& t, int i, int j)
{
    if (s[i]==t[j]) cout << "M";
    else cout << "S";
}

void delete_out(string& s, int i)
{
    cout << "D";
}

int match(char c, char d)
{
    if (c == d) return 0;
    else return 1;
}

int indel(char c)
{
    return 1;
}

int string_compare(string& s, string& t, int i, int j)
{
    int k;              // counter
    int opt[3];         // cost of the three options 
    int lowest_cost;    // lowest cost 

    //Check lookup table
    if(m[i][j] != -1) return m[i][j];

    if (i == 0) return(j * indel(' '));
    if (j == 0) return(i * indel(' '));

    opt[MATCH] = string_compare(s,t,i-1,j-1) + match(s[i],t[j]);
    opt[INSERT] = string_compare(s,t,i,j-1) + indel(t[j]);
    opt[DELETE] = string_compare(s,t,i-1,j) + indel(s[i]);

    lowest_cost = opt[MATCH];
    for (k=INSERT; k<=DELETE; k++){
        if (opt[k] < lowest_cost) lowest_cost = opt[k];
    }
    m[i][j] = lowest_cost;
    return( lowest_cost );
}

int main(){
    // Initialize Lookup table with sentinel value
    for (int i = 0; i < MAXLEN; i++){
        for(int j = 0; j < MAXLEN; j++){
            m[i][j] = -1;
        }
    }

    string str1 = "foog";
    string str2 = "money";
    cout << string_compare(str1, str2, str1.length()+1, str2.length()+1) << endl;
}

