#include <stack>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

bool delimiterMatching(char *file){

  char charatr;
  bool flagg;
  stack<char> stackk1;
  ifstream inStream;
  inStream.open(file, std::ifstream::in);

    while (inStream >> charatr){

	if(charatr == '(' || charatr == '[' || charatr == '{'){
	  stackk1.push(charatr);
	}else if(charatr == ')' || charatr == ']' || charatr == '}'){
	  if(stackk1.empty()){
	    return false;
          }else if(stackk1.top() == '(' && charatr == ')'){
	    stackk1.pop();
          }else if(stackk1.top() == '[' && charatr == ']'){
	     stackk1.pop();
	  }else if(stackk1.top() == '{' && charatr == '}'){
	     stackk1.pop();
	  }else if(charatr == '/'){
    		inStream>>charatr;
    		if(charatr=='*'){
      		  flagg=false;
		  stackk1.push(charatr);
      		while(inStream>>charatr && charatr != '*'){
}
 	        inStream>>charatr;
      		if(charatr == '/'){
        	  flagg = true;
		  stackk1.pop();
      		}
    }		else{
 			continue;
		}if(!stackk1.empty()){
			flagg = false;
			return flagg;
		}
	}else{
		inStream>>charatr;
}
}}	if(stackk1.empty()){
		return true;
}else{
	return false;
}


}

int main(int argc, char **argv){
  if(delimiterMatching(argv[1]) == true){
    cout<<"Input is delimiter matched\n";
  }else{
    cout<<"Input is not delimiter matched\n";
}
  return 0;
}

