// 
// This program allows the user to manipulate a binary heap.
// The program only inserts string ids with with associated keys
// into the heap. The heap class, however, is capable of storing
// arbitrary pointers along with each heap item.
//

#include <iostream>
#include <string>
#include <cstdlib>

#include "heap.h"

using namespace std;

int counter = 0; 
template<class T> 
void force(T input , T expectation, string message = "Invalid response"){
  if (input != expectation){
    cout << "Failure: " << message << "\ncounter: " << counter<< " expected: " << expectation << " revieved: " << input << "\n"; 
    exit(-1); 
  }
  counter++; 
}


int main(){
  heap h = heap(500);
  force<int>(h.insert("string one",35),0, "Insert return failure 1");
  force<int>(h.insert("string two",55),0, "Insert return failure 2");
  force<int>(h.insert("string three",45),0, "Insert return failure 3");
  force<int>(h.insert("string four",5),0, "Insert return failure 4");
  force<int>(h.insert("string two",10),2, "Insert return unseccseful");
  force<int>(h.insert("string five",80),0, "Insert return failure 5");
  force<int>(h.insert("string six",20),0, "Insert return failure 6");
  force<int>(h.insert("string seven",70),0, "Insert return failure 7");
  int key;
  string id; 
  force<int>(h.deleteMin(&id,&key),0);
  force<int>(key,5, "Incorrect Key"); 
  force<string>(id,"string four", "Incorrect id"); 
  force<int>(h.remove("string four",&key),1); 
  force<int>(h.deleteMin(&id,&key),0);
  force<int>(key,20, "Incorrect Key"); 
  force<string>(id,"string six", "Incorrect id");
  force<int>(h.setKey("string one", 50),0);
  force<int>(h.remove("string two",&key),0);
  force<int>(key,55); // current error key is populated wrong but 
  force<int>(h.deleteMin(&id,&key),0);
  force<int>(key,45, "Incorrect Key"); 
  force<string>(id,"string three", "Incorrect id");
  force<int>(h.deleteMin(&id,&key),0);
  force<int>(key,50, "Incorrect Key"); 
  force<string>(id,"string one", "Incorrect ID"); 
  force<int>(h.setKey("string five",60),0);
  force<int>(h.deleteMin(&id,&key),0);
  force<int>(key,60);
  force<string>(id,"string five"); 
  force<int>(h.deleteMin(&id,&key),0);
  force<int>(key,70);
  force<string>(id,"string seven"); 
  force<int>(h.deleteMin(&id,&key),1);

  cout << "Passed all tests\n"; 
}






// // Read an integer from standard input; if a non-integer is in the
// // buffer, the state is fixed and the user is re-prompted;
// // either way, the remainder of the buffer is cleared
// void getInteger(string message, int &ref)
// {
//   bool inputGood = false;
//   while (!inputGood) {
//     inputGood = true;

//     cout << message;
//     cin >> ref;

//     if (!cin) {
//       // Non-integer in input buffer, get out of "fail" state
//       cin.clear();
//       inputGood = false;
//     }
//     while (cin.get() != '\n'); // clear buffer
//   }
// }

// int main()
// {
//   int capacity = 0;
//   int option;
//   string stringTmp;
//   int key, id;
//   int retVal;

//   // Have user choose capacity for binary heap
//   getInteger("Choose a capacity for the binary heap: ", capacity);

//   // Create the heap
//   heap myHeap1(capacity);

//   while (1) {
//     cout << "\nOptions:\n";
//     cout << "1 - Insert a new item into the binary heap\n";
//     cout << "2 - Set the key of a specified item\n";
//     cout << "3 - Delete a specified item\n";
//     cout << "4 - Perform a deleteMin\n";
//     cout << "5 - Quit\n";

//     // Have the user choose an option
//     getInteger("Choose an option: ", option);
//     switch(option) {

//     case 1:
//       // Get data to insert into heap from the user and insert it

//       cout << "Enter an id string (to insert): ";
//       getline(cin, stringTmp);

//       getInteger("Enter an associated integer key: ", key);

//       retVal = myHeap1.insert(stringTmp, key);

//       cout << "\nCall to 'insert' returned: " << retVal << "\n";

//       break;

//     case 2:
//       // Get id string and new key from user and change the key

//       cout << "Enter an id string (to change its key): ";
//       getline(cin, stringTmp);

//       getInteger("Enter an associated integer key: ", key);

//       retVal = myHeap1.setKey(stringTmp, key);
//       cout << "\nCall to 'setKey' returned: " << retVal << "\n";

//       break;

//     case 3:
//       // Get id string from user and delete it from the heap

//       cout << "Enter an id string (to delete): ";
//       getline(cin, stringTmp);

//       retVal = myHeap1.remove(stringTmp, &key);
//       cout << "\nCall to 'delete' returned: " << retVal << "\n";

//       if (retVal == 0) {
// 	cout << "\nDeleted item with string id \"" << stringTmp
// 	     << "\" and key " << key << "\n";
//       }

//       break;

//     case 4:
//       // Perform the deleteMin operation on the heap

//       retVal = myHeap1.deleteMin(&stringTmp, &key);
//       cout << "\nCall to 'deleteMin' returned: " << retVal << "\n";

//       if (retVal == 0) {
// 	cout << "\nDeleted item with string id \"" << stringTmp
// 	     << "\" and key " << key << "\n";
//       }

//       break;

//     case 5:
//       cout << "\nGoodbye!\n";
//       exit(0);

//     default:
//       cerr << "Error, that input is not valid!\n";
//       exit (1);
//     }
//   }

//   cerr << "Error, we should never get here!\n";
//   exit (1);
// }