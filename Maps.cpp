#include <iostream>
#include <fstream>
#include <map>
#include <iterator>
#include <iomanip>
#include <string>
using namespace std;

void ReadMapText(map<string, int>& t){


	ifstream text;
	text.open("THFINALP2.txt");
	
	if(!text.is_open()){
	
	cout << "Error, Not able to open file." << endl;
	return;
	
	}

	
	string detail = "";
	
	cout << "<Importing the text, (The Old Man and the Sea)..>" << endl;
	
	while(!text.eof()){
	
	text >> detail;
	
	string holder = "";
	int i = 0;
		while(i < detail.size()){
	
		if(isalpha(detail[i])) holder.push_back(tolower(detail[i]));
		if(detail[i] == '\''|| detail[i] == '-') holder.push_back(detail[i]);
		i++;
	
	
	
		}
		
		
		if(holder == "i") holder[0] = toupper(holder[0]);
		t[holder]++;
	
	}




text.close();





} 






int main(){

 string Name;
/*****************************************/
cout << "Student Enter Name" << endl;
cin >> Name;
cout << "----------------------------------------------" << endl;
cout << "FIle: " << __FILE__ << " Date: " << __DATE__ << endl;
cout << "Student Name: " << Name << endl;
cout << "----------------------------------------------" << endl;
	/*****************************************/


map<string, int>::iterator it;

map<string, int> TM;
ReadMapText(TM);
cout << endl;

cout << left << setfill('~') << setw(34) << "Unique Words: " << setfill(' ') << endl;
cout << left << "Count: " << TM.size() << endl;
for(it = TM.begin(); it != TM.end(); it++){

cout << left << "Word: " << setw(15) << it->first
	<< "Reps: " << it->second << endl;

}

cout << left << setfill('~') << setw(34) << "" << setfill(' ') << endl;


cout << endl;



string Mwords[] = {"love", "death", "money", "blood", "lips", "he", "she", "hero", "coward", "eyes", "mouth", "years", "best",
"bed", "table", "ice", "fish", "animal", "sky", "glass", "wine", "liquor", "old", "young", "man", "big", "small", "home", "road", 
"chair", "table", "boy", "boat", "food", "door","window", "days", "weeks", "wind", "sea", "ice", "water", "wind", "they", "the", "and", "week", "I", "of"};


cout << "Checking for the magic words: " << endl;

map<string, int> MagicMap;
for(int i = 0; i < sizeof(Mwords)/sizeof(string); i++){

	for(it = TM.begin(); it != TM.end(); it++){
	
		if(it->first == Mwords[i]){
		
		pair<string, int> place(it->first, it->second);
		MagicMap.insert(place);
		break;
		}
	
	
	
	}


}

cout << left << setfill('~') << setw(34) << "The Magic Words Are: " << setfill(' ') << endl;
cout << left << "Count: " << MagicMap.size() << endl;

for(it = MagicMap.begin(); it != MagicMap.end(); it++){

	cout << left << "Words: " << setw(15) << it->first
	<< "Reps: " << it->second << endl;
		

}

cout << left << setfill('~') << setw(34) << "" << setfill(' ') << endl;

}
