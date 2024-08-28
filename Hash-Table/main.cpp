// trees

#include <iostream>
#include <sstream>
#include <string>

#define ARRAY_SIZE 26
//#define KEY_SIZE 11

class Table{
	public:
		// default constructor
		Table();
		~Table(){};

		Table* insert(std::string e, Table* t);
		Table* remove(std::string e, Table* t);
		
		bool find(std::string e);
		char hash(std::string e);

		// print keys
		void output(Table* t);
	private:
		std::string status[ARRAY_SIZE];
		std::string keys[ARRAY_SIZE];
};

Table::Table(){
	std::string val;
	for (int i=0; i<ARRAY_SIZE; i++){
		status[i].assign("never used");
		val = char(i+97);
		keys[i].assign("-");
	}
}

bool Table::find(std::string e){
	char hval = hash(e);
	// find corresponding slot to the hash value
	int num = int(hval-97);

	for (int i=num; i<ARRAY_SIZE; i++){
		if (i == num-1){
			return false;
		}

		if (status[i].compare("never use") == 0){
			return false;
		} else if (status[i] == "occupied" && keys[i].compare(e) == 0){
			return true;
		}

		if (i == ARRAY_SIZE-1 && num != 0){
			i=-1;
		}
	}
	return false;
}

Table* Table::insert(std::string e, Table* t){
	if (t->find(e) == true){
		return t;
	}
	char hval = hash(e);
	int num = int(hval-97);
	for (int i=num; i<ARRAY_SIZE; i++){
		if (status[i] == "never used" || status[i] == "tombstone"){
			keys[i].assign(e);
			status[i] = "occupied";
			return t;
		}
		if (i == ARRAY_SIZE-1 && num != 0){
			i = -1;
		} else if (i == num-1){
			break;
		}
	}
	return t;
}

Table* Table::remove(std::string e, Table* t){
	if (find(e) == false){
		return t;
	}
	char hval = hash(e);
	int num = int(hval-97);
	for (int i=num; i<ARRAY_SIZE; i++){
		if (keys[i].compare(e) == 0){
			status[i] = "tombstone";
			return t;
		}
		if (i == ARRAY_SIZE-1 && num != 0){
			i = -1;
		} else if (i == num-1){
			break;
		}
	}
	return t;
}

char Table::hash(std::string e){
	int len = e.size();
	char val = e[len-1];
	return val;
}

void Table::output(Table* t){
	for(int i=0; i<ARRAY_SIZE; i++){
		if (status[i] == "occupied"){
			std::cout << keys[i] << " ";
		}
	}
	std::cout << std::endl;
}

int main(){
	// get input
	std::string mystring, tempString;
	getline(std::cin, mystring);
	std::stringstream stream(mystring);
	char move = ' ';

	Table* t = new Table();

	// moves	A=insert D=delete
	while (getline(stream, tempString, ' ')){
		if (tempString[0] == 'A' || tempString[0] == 'D') {
			// get the move
			move = tempString[0];
			// get the key
			tempString = tempString.erase(0,1);
			switch(move){
				case 'A':
					t->insert(tempString, t);
					break;
				case 'D':
					t->remove(tempString, t);
					break;
			}
		}
	}

	t->output(t);
	delete t;
	return 0;
}
