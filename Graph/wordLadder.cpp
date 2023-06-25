//Leetcode: 127. Word Ladder
//LINK: https://leetcode.com/problems/word-ladder

/*Problem: Our target is to find minimum steps required to reach target word fron begin word and 
all the newly created word must be present in given dict*/

/* Approach: We, will do BFS traversal and we will transform every charcter of word into all possible characters i.e 'a'->'z'
 and for every newly form word we will chk if it lie in dict is yes then push it into queue
 We will maintain set to store strings for easy retrieval*/

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        //create set to make searching easier
        unordered_set <string> s(wordList.begin(), wordList.end());

        //create queue for BFS traversal
        queue<pair<string, int>> q;

        //insert starting word
        q.push({beginWord, 1});

        //erase it from set to avoid revisiting it
        s.erase(beginWord);

        while(!q.empty()){
            string word=q.front().first;
            int steps= q.front().second;
            q.pop();

            //target word found successfully
            if(word==endWord) return steps;

            //traverse each char of word
            for(int i=0; i<word.size(); i++){
                char ch=word[i];
                //convert char into all possible char and check if after conversion particular word is present in set or not
                for(char j='a'; j<='z'; j++){
                    word[i]=j;

                    //word is present in set then
                    if(s.find(word)!=s.end()){

                        //insert word into queue
                        q.push({word, steps+1});

                        //erase it from set
                        s.erase(word);
                    }

                    //backtack
                    word[i]=ch;
                }
            }

        }
        //if targetword not found
        return 0;
        
    }
};

//TC: O(N*M*26)
//SC: O(N)
