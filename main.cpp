/*
 *
 * Calculator program for Rayan
 * Compile, build, and run: make
 *
 */
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

// http://stackoverflow.com/a/393027
double string_to_double( const std::string& s ) {
   std::istringstream i(s);
   double x;
   if (!(i >> x))
     return 0;
   return x;
} 

int main() {
  bool debug = false;
  cout << "Welcome to my calculator!\n"; //  << endl
  string command;
  while(1==1) {
    cout << "> ";
    getline(cin, command);
    if(command=="help") {
        cout << "Example commands\n";
        cout << "help\n";
        cout << "quit\n";
        cout << "+ 5 2\n";
        cout << "- 5 2\n";
    } else if(command=="quit") {
        cout << "Bye\n";
        return 0;
    } else {
        istringstream iss(command);
        vector<string> tokens;
        do {
          string sub;
          iss >> sub;
          //cout << "Substring: " << sub << endl;
          if(sub!=" ") tokens.push_back(sub);
        } while (iss);

        if(debug) {
          cout << "Command length: " << tokens.size() << endl;
          for(int i=0;i<tokens.size();i++) {
            cout << "Command " << i << " : " << tokens[i] << endl;
          }
        }

        if(tokens.size()!=4) {
          cout << "Invalid format. Check help\n";
        } else {
          if(tokens[0]=="+") {
            if(debug) cout << "Addition\n";
            cout << string_to_double(tokens[1])+string_to_double(tokens[2])<<endl;
          } else if(tokens[0]=="-") {
            if(debug) cout << "Subtraction\n";
            cout << string_to_double(tokens[1])-string_to_double(tokens[2])<<endl;
          } else {
            cout << "Invalid format. Check help\n";
          }
        }
    } // end if else
  } // end while true

  return 0;
}


