class Solution {
public:
    bool isLL(string &str){
        stringstream ss(str);
        string word;
        ss>>word;
        ss>>word;
        if(isdigit(word[0])) return false;
        return true;
    }
    static bool comparator(string &a, string &b){
        
        stringstream ss1(a);
        stringstream ss2(b);
        string id1,id2;
        ss1>>id1;
        ss2>>id2;
        string c1,c2;
        while(ss1>>c1&&ss2>>c2){
                if(c1<c2) return true;
                else if(c1>c2) return false;
        }  
        if(ss1>>c1) return false;
        if(ss2>>c2) return true;
        return id1<id2;
    }
    vector<string> reorderLogFiles(vector<string>& logs) {
        vector<string> ll;
        vector<string> dl;
        for(string str:logs){
            if(isLL(str)){
                ll.push_back(str);
            }
            else
                dl.push_back(str);
        }
        sort(ll.begin(),ll.end(),comparator);
        vector<string> ans;
        for(auto str:ll)
            ans.push_back(str);
        for(auto str:dl)
            ans.push_back(str);
        return ans;
    }
};