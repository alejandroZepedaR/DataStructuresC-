#include <string>
#include "personType.h"

const int NO_OF_REGIONS = 4;

class candidateType: public personType
{

public:
    const candidateType& operator=(const candidateType&);
    const candidateType& operator=(const personType&);
    void updateVotesByRegion(int region, int votes);
    void setVotes(int region, int votes);
    void calculateTotalVotes();
    int getTotalVotes() const;
    void printData() const;
    candidateType();

    bool operator==(const candidateType& right) const;
    bool operator!=(const candidateType& right) const;
    bool operator<=(const candidateType& right) const;
    bool operator<(const candidateType& right) const;
    bool operator>=(const candidateType& right) const;
    bool operator>(const candidateType& right) const;

private:
    int votesByRegion[NO_OF_REGIONS];
    int totalVotes;
};

void candidateType::setVotes(int region, int votes)
{
    votesByRegion[region -1] = votes;
}

void candidateType::updateVotesByRegion(int region, int votes)
{
    votesByRegion[region -1] = votesByRegion[region -1] + votes;
}

void candidateType::calculateTotalVotes()
{
    totalVotes = 0;

    for (int i = 0; i < NO_OF_REGIONS; i++)
        totalVotes += votesByRegion[i];
}
int candidateType::getTotalVotes() const
{
    return totalVotes;
}
void candidateType::printData() const
{
    cout<<left<<setw(8)<<firstName<<" "<<setw(8)<<lastName<<" ";
    cout<<right;
    for (int i = 0; i<NO_OF_REGIONS; i++)
        cout<<setw(8)<<votesByRegion[i]<<" ";
    cout<<setw(7)<<totalVotes<<endl;
}

candidateType::candidateType()
{
    for (int i = 0; i< NO_OF_REGIONS; i++)
        votesByRegion[i] = 0;
    
    totalVotes = 0;
}

bool candidateType::operator==(const candidateType& right) const
{
    return(firstName == right.firstName && lastName == right.lastName);
}
bool candidateType::operator!=(const candidateType& right) const
{
    return(firstName != right.firstName || lastName != right.lastName);
}

bool candidateType::operator<=(const candidateType& right) const
{
    return(lastName <= right.lastName || (lastName == right.lastName && firstName <= right.firstName));
}

bool candidateType::operator<(const candidateType& right) const
{
    return(lastName < right.lastName || (lastName == right.lastName && firstName < right.firstName));
}
bool candidateType::operator>=(const candidateType& right) const
{
    return (lastName >= right.lastName || (lastName == right.lastName && firstName >= right.firstName));

}
bool candidateType::operator>(const candidateType& right) const
{
    return(lastName > right.lastName || (lastName == right.lastName && firstName > right.firstName));
}
const candidateType& candidateType::operator=(const candidateType& right)
{
    if(this != &right)
    {
        firstName = right.firstName;
        lastName = right.lastName;

        for(int i = 0; i< NO_OF_REGIONS; i++)
            votesByRegion[i]=right.votesByRegion[i];
        
        totalVotes = right.totalVotes;
    }
    return *this;
}

const candidateType& candidateType::operator=(const personType& right)
{
    firstName = right.getFirstName();
    lastName = right.getLastName();

    return *this;
}