# programming challenge
# Reverse a String
# C++
# binariusO1

#include <bits/stdc++.h>
int main() {
	std::string s;
	getline(std::cin,s);
	reverse(s.begin(),s.end());
	std::cout<<s<<'\n';
}
