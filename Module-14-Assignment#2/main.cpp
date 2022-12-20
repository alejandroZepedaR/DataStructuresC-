#include <iostream>
#include <string>
#include <fstream>
#include "candidateType.h"
#include "unorderedArrayListType.h"

using namespace std;
const int NO_OF_CANDIDATES = 6;

void printResults(const unorderedArrayListType<candidateType>& cList)
{
    candidateType temp;
    candidateType winner;
    int totalVotesPolled = 0;

    for (int i = 0; i<cList.listSize(); i++)
    {
        cList.retrieveAt(i, temp);
        temp.printData();
        totalVotesPolled += temp.getTotalVotes();

        if(i == 0 || temp.getTotalVotes() > winner.getTotalVotes())
        {
            winner = temp;
        }
    }
    cout <<endl << "Winner: "<<winner<<", Votes Recieved: "<<winner.getTotalVotes()<<endl;
    cout<<endl<<"Total votes polled: "<<totalVotesPolled<<endl;
}