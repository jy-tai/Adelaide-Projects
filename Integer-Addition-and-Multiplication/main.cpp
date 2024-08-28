// school method for integer addition
// karatsuba algorithm for integer multiplication

#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <math.h>

// functions
std::vector<int> add(std::vector<int> num1, std::vector<int> num2, int base);
std::vector<int> karatMult(std::vector<int> num1, std::vector<int> num2, int base);
std::vector<int> schoolMult(std::vector<int> num1, std::vector<int> num2, int base);
std::vector<int> subtraction(std::vector<int> num1, std::vector<int> num2, int base);


int main(){
	// get input
	std::string mystring, tempString;
	getline(std::cin, mystring);
	std::stringstream stream(mystring);
	int len = 0;

	int digit = 0;
	std::vector<int> i1, i2;
	int base;

	// i1
	getline(stream, tempString, ' ');
	len = tempString.length();
	for (int i=0; i<len; i++){
		digit = int(tempString[i])-48;
		i1.push_back(digit);
	}
	// i2
	getline(stream, tempString, ' ');
	len = tempString.length();
	for (int i=0; i<len; i++){
		digit = int(tempString[i])-48;
		i2.push_back(digit);
	}
	
	// base
	getline(stream, tempString, ' ');
	len = tempString.length();
	base = stoi(tempString);


	// sum
	std::vector<int> sumVec = add(i1,i2,base);

	// multiply
	std::vector<int> productVec = karatMult(i1,i2,base);

	// output
	for (auto i:sumVec){
		std::cout << i;
	}
	std::cout << " ";

	for (auto i:productVec){
		std::cout << i;
	}
	std::cout << " 0" << std::endl;

	return 0;
}



std::vector<int> add(std::vector<int> num1, std::vector<int> num2, int base){
	if (num1.empty()){
		num1.push_back(0);
	} else if (num2.empty()){
		num2.push_back(0);
	}

	// remove leading zeroes
	while (num1.front()==0 && num1.size()>1){
		num1.erase(num1.begin());
	}
	while (num2.front()==0 && num2.size()>1){
		num2.erase(num2.begin());
	}
//std::cout << "num1: ";
//for(auto i:num1){
//	std::cout << i;
//} std::cout << "	";
//std::cout << "num2: ";
//for(auto i:num2){
//	std::cout << i;
//} std::cout << std::endl;

	
	bool neg = false;
	if (num1.front()<0 && num2.front()<0){
		neg = true;
		num1.front() = -num1.front();
		num2.front() = -num2.front();
	} else if (num1.front()<0){
		num1.front() = -num1.front();
		return subtraction(num2,num1,base);
	} else if (num2.front()<0){
		num2.front() = -num2.front();
		return subtraction(num1,num2,base);
	}


	// length of the numbers
	int len1 = num1.size();
	int len2 = num2.size();
	int lenSmall = 0;
	int cdigit = 0;	// digits of the carries
	std::vector<int> larger;
	std::vector<int> smaller;

	// reversed num1 and num2
	std::vector<int> temp1, temp2;

	// find larger number	
	if (len1 > len2){
		larger = num1;
		smaller = num2;
		cdigit = len1+1;
		lenSmall = len2;
		// reverse the two vectors
		for (int i=0; i < len1; i++){
			temp1.push_back(larger.at(len1-1-i));
		}
		for (int i=0; i < len2; i++){
			temp2.push_back(smaller.at(len2-1-i));
		}	
	} else{
		larger = num2;
		smaller = num1;
		cdigit = len2+1;
		lenSmall = len1;
		// reverse the two vectors
		for (int i=0; i < len2; i++){
			temp1.push_back(larger.at(len2-1-i));
		}
		for (int i=0; i < len1; i++){
			temp2.push_back(smaller.at(len1-1-i));
		}	
	}

	// calculate carries
	std::vector<int> tempCarry;
	tempCarry.push_back(0);
	for (int i=0; i < cdigit-1; i++){
		if (i < lenSmall){
			if (temp1.at(i)+temp2.at(i)+tempCarry.at(i) >= base){
				tempCarry.push_back(1);
			} else {
				tempCarry.push_back(0);
			}
		} else if (temp1.at(i)+tempCarry.at(i) >= base){
			tempCarry.push_back(1);
		} else{
			tempCarry.push_back(0);
		}
	}

	// perform addition
	std::vector<int> tempSum;
	for (int i=0; i < cdigit; i++){
		if ( i < lenSmall){
			tempSum.push_back((temp1.at(i) + temp2.at(i) + tempCarry.at(i))%base);

		} else if (i < cdigit-1){
			tempSum.push_back((temp1.at(i) + tempCarry.at(i))%base);
		} else {
			tempSum.push_back(tempCarry.at(i));
		}
	}

	std::vector<int> sum;
	int lenSum = tempSum.size();
	for (int i=0; i<lenSum; i++){
		sum.push_back(tempSum.at(lenSum-1-i));
	}
//	if (sum.front()==0 && sum.size()>1){
//		sum.erase(sum.begin());
//	}
	if(sum.front()==0 && sum.size()>0){
		sum.erase(sum.begin());
	}
	if (neg){
		sum.front() = -sum.front();
	}
//std::cout<< std::endl << "sum: ";
//for(auto i:sum){
//	std::cout << i;
//} std::cout << std::endl<<std::endl;
	return sum;
}

std::vector<int> karatMult(std::vector<int> a, std::vector<int> b, int base){
//std::cout << "a: ";
//for(auto i:a){
//	std::cout << i;
//} std::cout << "	";
//
//std::cout << "b: ";
//for(auto i:b){
//	std::cout << i;
//} std::cout << std::endl;

	int n1 = a.size();
	int n2 = b.size();

	if (n1<4 || n2<4){
		return schoolMult(a,b,base);
	}

//	int k = 0;
	if (n1 <= n2){
//		k = n1;
		if (n2%2!=0){
			n2++;
			b.insert(b.begin(),0);
		}
		while (n1 < n2){
			a.insert(a.begin(),0);
			n1 = a.size();
		}
	} else if (n1 > n2){
//		k = n2;
		if (n1%2!=0){
			n1++;
			a.insert(a.begin(),0);
		}
		while (n1 > n2){
			b.insert(b.begin(),0);
			n2 = b.size();
		}
	}

	int k = n1;
	k /= 2;


	std::vector<int> a0,a1,b0,b1;

	if (n1 >= 4){
		for (int i=0; i<k; i++){
			a1.push_back(a.at(i));
		}
		for (int i=k; i<n1; i++){
			a0.push_back(a.at(i));
		}
	}

	if (n2 >= 4){
		for (int i=0; i<k; i++){
			b1.push_back(b.at(i));
		}
		for (int i=k; i<n2; i++){
			b0.push_back(b.at(i));
		}
	}
//std::cout << "a, a1, a0: ";
//for(auto i:a){
//	std::cout << i;
//} std::cout << " ";
//for(auto i:a1){
//	std::cout << i;
//} std::cout << " ";
//for(auto i:a0){
//	std::cout << i;
//} std::cout << std::endl;
//
//std::cout << "b, b1, b0: ";
//for(auto i:b){
//	std::cout << i;
//} std::cout << " ";
//for(auto i:b1){
//	std::cout << i;
//} std::cout << " ";
//for(auto i:b0){
//	std::cout << i;
//} std::cout << std::endl;

	std::vector<int> p0,p1,p2,sum1,sum2;
	sum1 = add(a1,a0,base);
	sum2 = add(b1,b0,base);
	p2 = karatMult(a1,b1,base);
	p1 = karatMult(sum1,sum2,base);
	p0 = karatMult(a0,b0,base);

	// for shifting
	// x=2k, y=k
	int x,y;
	x = 2*k;
	y = k;

	std::vector<int> par1, par2, par3;
	par1 = p2;
	if (par1.front()!=0){
		for (int i=0; i<x; i++){
			par1.push_back(0);
		}
	}
	par2 = subtraction(p1,add(p2,p0,base),base);
	if (par2.front()!=0){
		for (int i=0; i<y; i++){
			par2.push_back(0);
		}
	}
	// return 3partial sums
	return add(par1,add(par2,p0,base),base);
}


// school multiplication
std::vector<int> schoolMult(std::vector<int> vec1, std::vector<int> vec2, int base){
	int len1,len2;
	len1 = vec1.size();
	len2 = vec2.size();

	// reverse the numbers;
	std::vector<int> n1,n2;
	for (auto i:vec1){
		n1.insert(n1.begin(),i);
	}
	for (auto i:vec2){
		n2.insert(n2.begin(),i);
	}

	if (len2 > len1){
		std::vector<int> temp;
		temp = n1;
		n1 = n2;
		n2 = temp;
		int templen;
		templen = len1;
		len1 = len2;
		len2 = templen;
	}

	std::vector<int> p1,product;
	int num1,b1,b2,b;
	for (int i=0; i<len1; i++){
		b1 = i;
		for (int j=0; j<len2; j++){
			b2 = j;
			b = b1 + b2;
			num1 = n1.at(i) * n2.at(j);
			while (num1 != 0){
				p1.insert(p1.begin(),num1%base);
				num1 /= base;
			}
			while (b!=0){
				p1.push_back(0);
				b--;
			}
			if (product.empty()){	
				product = p1;
			} else {
				product = add(product,p1,base);
			}
			p1.clear();
		}
	}

	return product;
}




std::vector<int> subtraction(std::vector<int> num1, std::vector<int> num2, int base){
	// length of the numbers
	int len1 = num1.size();
	int len2 = num2.size();

	// make temp1 the larger number and temp2 the smaller number
	// swap to keep track whether the two numbers are swapped
	bool swap = false;
	if (len1 == len2){
		for (int i=0; i<len1; i++){

			if (num1.at(i)>num2.at(i)){
				break;
			} else if (num1.at(i)<num2.at(i)){
				swap = true;
				int templen;
				templen = len1;
				len1 = len2;
				len2 = templen;
				break;
			}
		}
		// if both numbers are equal
		if (swap == false){
			std::vector<int> diff;
			diff.push_back(0);
		}
	} else if (len1 < len2){
		swap = true;
		int templen;
		templen = len1;
		len1 = len2;
		len2 = templen;
	}

	// swap the numbers;
	std::vector<int> temp1, temp2;
	if (swap == false){
		for (auto i:num1){
			temp1.push_back(i);
		}
		for (auto j:num2){
			temp2.push_back(j);
		}
	} else if (swap == true){
		for (auto i:num2){
			temp1.push_back(i);
		}
		for (auto j:num1){
			temp2.push_back(j);
		}
	}

	// reverse the two numbers
	std::vector<int> s1, s2;
	for (auto i:temp1){
		s1.insert(s1.begin(),i);
	}
	for (auto j:temp2){
		s2.insert(s2.begin(),j);
	}

	// subtraction
	std::vector<int> tempSub;

	for (int i=0; i<len1; i++){
		if (i<len2){
			// "borrow" digits
			if (s1.at(i)<s2.at(i)){
				int n = i;
				while (s1.at(n+1)==0 && n<len1){
					s1.at(n+1) = base-1;
					n++;
				} s1.at(n+1) = s1.at(n+1)-1;
				tempSub.push_back(base+s1.at(i)-s2.at(i));
			} else {
				tempSub.push_back(s1.at(i)-s2.at(i));
			}
		} else {
				tempSub.push_back(s1.at(i));
			}
//std::vector<int> x;
//for(auto i:tempSub){
//	x.insert(x.begin(),i);
//}
//std::cout << "ori sub: ";
//for(auto i:s1){
//	std::cout << i;
//} std::cout << std::endl;
//std::cout << "temp sub: ";
//for(auto i:x){
//	std::cout << i;
//} std::cout << std::endl;


	}


	// get final result
	std::vector<int> diff;
	int n = tempSub.size();
	for (int i=0; i<n; i++){
		diff.push_back(tempSub.at(len1-1-i));
	}
	if (s1.back() == 0){
		diff.erase(diff.begin());
	}
	if (swap == true){
		diff.front() = -diff.front();
	}

	// trimming leading zeroes
	while(diff.size()>1){
		if (diff.at(0)!=0){
			break;
		}
		diff.erase(diff.begin());
	}

//std::cout << "difference: ";
//for(auto i:diff){
//	std::cout << i;
//} std::cout << std::endl;


	return diff;
}


