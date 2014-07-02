#include "flow.h"

#include <iostream>
#include <string>

using namespace std ;



int main()
{
	vector<char> characters ;
	int n ;
	string S1 , S2 ;

	cin >> n ;
	cin >> S1 >> S2 ;
	
	Flow myFlow(2*n) ;   
	map < char , int > nodeNumber ;
	
	nodeNumber[ '0' ] = 1 ;
	nodeNumber[ '1' ] = 2 ;
	
	int currentNum = 3 ;
	for( int i=0 ; i<n ; i++ )
	{
		if( nodeNumber.find( S1[i] ) == nodeNumber.end() )
		{
			nodeNumber[ S1[i] ] = currentNum ;
			//cerr << "node added" << S1[i] << " " << nodeNumber[ S1[i] ] << endl ;
			characters.push_back( S1[i] ) ;
			currentNum++ ;
		}
		if( nodeNumber.find( S2[i] ) == nodeNumber.end() )
		{
			nodeNumber[ S2[i] ] = currentNum ;
			//cerr << "node added" << S2[i] << " " << nodeNumber[ S2[i] ] << endl ;
			characters.push_back( S2[i] ) ;
			currentNum++ ;
		}
		myFlow.push_back( nodeNumber[ S1[i] ] , nodeNumber[ S2[i] ] , 1 ) ;
		myFlow.push_back( nodeNumber[ S2[i] ] , nodeNumber[ S1[i] ] , 1 ) ;
		//cerr <<"connecting:  "<< nodeNumber[ S1[i] ]<<"  "<< nodeNumber[ S2[i] ] << endl; 

	}

	myFlow.maxFlow( nodeNumber['0'] , nodeNumber['1'] ) ;

	for( int i=0 ; i< characters.size() ; i++ )
	{
		cout << characters[i] << " " << !myFlow.getDiv() [ nodeNumber[ characters[i] ]  ] << endl ;
	}

	return 0 ;
}
