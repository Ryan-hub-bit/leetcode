// Given two sentences words1, words2 (each represented as an array of strings), and a list of similar word pairs pairs, determine if two sentences are similar.
//
// For example, "great acting skills" and "fine drama talent" are similar, if the similar word pairs are pairs = [["great", "fine"], ["acting","drama"], ["skills","talent"]].
//
// Note that the similarity relation is not transitive. For example, if "great" and "fine" are similar, and "fine" and "good" are similar, "great" and "good" are not necessarily similar.
//
// However, similarity is symmetric. For example, "great" and "fine" being similar is the same as "fine" and "great" being similar.
//
// Also, a word is always similar with itself. For example, the sentences words1 = ["great"], words2 = ["great"], pairs = [] are similar, even though there are no specified similar word pairs.
//
// Finally, sentences can only be similar if they have the same number of words. So a sentence like words1 = ["great"] can never be similar to words2 = ["doubleplus","good"].
//
// Note:
//
//
// 	The length of words1 and words2 will not exceed 1000.
// 	The length of pairs will not exceed 2000.
// 	The length of each pairs[i] will be 2.
// 	The length of each words[i] and pairs[i][j] will be in the range [1, 20].
//
//
//  
//


class Solution {
public:
    bool areSentencesSimilar(vector<string>& words1, vector<string>& words2, vector<vector<string>>& pairs) {
        if(words1.size() != words2.size()) {return false;}
        for(int i = 0;i < words2.size();i++){
            bool flag = false;
            if(words1[i] == words2[i]) continue;
            for(int j = 0;j < pairs.size();j++){
                if(words1[i] == words2[i] ||
                   pairs[j][0] == words1[i] && pairs[j][1] == words2[i] || 
                   pairs[j][1] == words1[i] && pairs[j][0] == words2[i]){
                    flag = true;
                    break;
                }
            }
            if(!flag) return false;
        }
        return true;
    }
};
