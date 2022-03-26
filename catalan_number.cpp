// count all possible stack sequence 
// actually Catalan number
// some info: https://en.wikipedia.org/wiki/Catalan_number
#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <fstream>

using namespace std;

// analyze
int valid_stack(string filename,int element_count,int factorial, string input){
    // build a push sequence
    vector<char> push_sequence;
    for(int i=0;i<element_count;i++){
        char temp_char=input[i];
        push_sequence.push_back(temp_char);
    }
    // build all pop sequence
    vector<vector<char>> pop_sequence(factorial, vector<char>(element_count,'0'));
    ifstream file(filename, ios::in);
    if(file.is_open()){
        int vec_count=0;
        string temp_str;
        while(file>>temp_str){
            for(int i=0;i<temp_str.size();i++){
                char character=temp_str[i];
                pop_sequence[vec_count][i]=character;
            }
            vec_count++;
        }        
    }
    else{
        cout<<"> Error reading file\n";
        return -1;
    }    
    // analyze for result
   int result=0;
   for(int m=0;m<pop_sequence.size();m++){
      stack<char> my_stack;
      // push for stack
      int pop_idx=0;
      for(int i=0;i<push_sequence.size();i++){
          my_stack.push(push_sequence[i]);
          while(!my_stack.empty()&&my_stack.top()==pop_sequence[m][pop_idx]){
              my_stack.pop();
              pop_idx++;
          }
      }
      if(my_stack.empty())result++;
   }
   return result;
}

// run
void run(){
    string filename[5]={"ABC.csv","ABCD.csv","ABCDE.csv","ABCDEF.csv","ABCDEFG.csv"};
    int element_count[5]={3,4,5,6,7};
    int factorial[5]={6,24,120,720,5040};
    string input[5]={"ABC","ABCD","ABCDE","ABCDEF","ABCDEFG"};
    cout<<"=======Valid Stacks Reuslt=======\n";
    for(int i=0;i<5;i++){
        cout<<filename[i]<<"\b\b\b\b";
        for(int j=0;j<7-element_count[i];j++){
            cout<<" ";
        }
        cout<<" result:  "<<valid_stack(filename[i],element_count[i],factorial[i],input[i])<<" valid sequences\n";
    }
    cout<<"=================================\n\n";
}

int cal_fac(int n){
    if(n==0)return 1;
    else if(n==1)return 1;
    else{
        unsigned long long int result=1;
        for(int i=1;i<=n;i++){
            result=result*i;         
        }
        return result;
    }
}

// Catalan number
void Catalan(){
    cout<<"=========Catalan Number==========\n";
    cout<<"> Background theorem\n";
    cout<<"> more info: https://en.wikipedia.org/wiki/Catalan_number"<<endl<<endl;
    
    for(int i=0;i<=6;i++){
        unsigned long long int up=cal_fac(2*i);
        unsigned long long int down=cal_fac(i+1);
        unsigned long long int down1=cal_fac(i);
        cout<<"> "<<i<<" th: "<<(up/down)/down1<<endl;
    }
    
    cout<<"=================================\n\n";
}

int main(){
    
    
    run();
    
    Catalan();
    
    system("pause");
    return 0;
}
