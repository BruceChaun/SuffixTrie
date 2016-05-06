#include <iostream>
#include "SuffixTrie.h"

using namespace std;

/*
 *  output each node info to check correctness
 */
void output(SuffixNode* n, string last = "")
{
        map<string, SuffixNode*> m = n->get_children();
        string children = "";

        for (std::map<string, SuffixNode*>::iterator iter = m.begin(); iter != m.end(); ++iter) {
            string s = iter->first;
            children += s + " ";
        }

        string parent = n->get_suffix_link() ? last : "root";
        cout << parent << " in " << n->get_path() << "\thas child: " 
            << children << "\tsuffix link: ";
        if (parent != "root")
            cout << n->get_suffix_link()->get_path() << endl;
        else
            cout << "NONE\n";

        for (std::map<string, SuffixNode*>::iterator iter = m.begin(); iter != m.end(); ++iter) {
            string s = iter->first;
            SuffixNode* sn = iter->second;
            output(sn, s);
        }
}

/*
 *  output all the suffix via
 *  the deepest node
 */
void output_suffix(SuffixNode *longest)
{
    while (longest) {
        cout << longest->get_path() << endl;
        longest = longest->get_suffix_link();
    }
}

int main(int argc, char *argv[])
{
    string s = argv[1];
    //string q = argv[2];

    SuffixTrie* trie = new SuffixTrie();
    trie->build_suffix_trie(s+"$");

    SuffixNode* root = trie->get_trie_root();
    SuffixNode* longest = trie->get_deepest_leaf();

    cout << "print trie stucture\n";
    output(root);
    cout << "print suffix link\n";
    output_suffix(longest);
}
