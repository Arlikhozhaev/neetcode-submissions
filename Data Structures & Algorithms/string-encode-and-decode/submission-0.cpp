class Solution {
public:

    string encode(vector<string>& strs) {
        string encoded = "";

        for(const string& str : strs) {
            encoded += to_string(str.length()) + "#" + str;
        } 

        return encoded;
    }

    vector<string> decode(string s) {
        vector<string> decoded;
        size_t i = 0; 

        while(i < s.length()) {
            size_t delimeter_pos = s.find('#', i);
            int length = stoi(s.substr(i, delimeter_pos - i));

            i = delimeter_pos + 1; 

            decoded.push_back(s.substr(i, length));

            i += length;
        }

        return decoded; 
    }
};
