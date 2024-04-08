class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) 
    {
        int i=0,j=0;
        while(j<sandwiches.size())
        {
            if(find(students.begin(),students.end(),sandwiches[i])!=students.end())
            {   
                if(students[i]==sandwiches[j])
                {
                    students.erase(students.begin()+i);
                    sandwiches.erase(sandwiches.begin()+j);
                }
                else
                {
                    students.push_back(students[i]);
                    students.erase(students.begin()+i);
                }
            }
            else
            {
                return students.size();
            }
        }
        return 0;
    }
};
