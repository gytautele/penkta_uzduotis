#include <iostream>
#include <map>
#include <algorithm>
#include <sstream>
#include <fstream>
#include <regex>
#include <set>

using std::getline;
using std::ifstream;
using std::string;
using std::map;
using std::istringstream;
using std::remove_if;
using std::ofstream;
using std::endl;

//-------------------------------------------------------------------------------
void nuskaityti(ifstream &fd , map<string , size_t> &zodziu_sk , map<string , map<size_t , size_t>> &references,  map<string , size_t> &linkas) {

    string eilute;
    unsigned int eilNr = 1;

    while (getline(fd, eilute)) {

        std::transform(eilute.begin(), eilute.end(), eilute.begin(), tolower);
        std::stringstream zod(eilute);
        string word;

        while (zod >> word) {

            word.erase(remove_if(word.begin(), word.end(), [](char s) {
                           return s == ',' || s == '-' || s == '.' || s == '!' || s == '?' || s == '(' || s == ')' ||
                                  s == '„' || s == '“';
                       }),
                       word.end());

            for (string w; zod >> w;) {

                if (std::regex_match(w, std::regex(
                        "[(http(s)?):\\/\\/(www\\.)?a-zA-Z0-9@:%._\\+~#=]{2,256}\\.[a-z]{2,6}\\b([-a-zA-Z0-9@:%_\\+.~#?&//=]*)"))) {
                    linkas.insert(std::pair<std::string, int>(w, eilNr));
                }

                zodziu_sk[w]++;
                references[w][eilNr]++;

            }

        }
        eilNr++;
    }

    fd.close();
}
//---------------------------------------------------------------------------------
void isvesti(ofstream &fr , map<string , size_t> &zodziu_sk , const map<string , map<size_t , size_t>> &references, map<string , size_t> &linkas) {

    fr << "Url adresai:" <<endl;
    for (auto &linka : linkas) {
        fr<<"'" << linka.first << "' "<<" eiluteje : "<< linka.second<<std::endl;
    }
    fr << endl;

    fr << "Zodziai ir ju daznis:" <<endl;

    for (auto &i : zodziu_sk) {
        if (i.second > 1){
            fr << " '"<< i.first <<"' " << "is viso pasikartojo " << i.second << " kartus:" << endl;
            for (auto &j : references.at(i.first)){
                fr << j.first << " eiluteje(-ese) " << j.second << " karta(-us)" << endl;
            }
            fr << endl;
        }
    }


}
//--------------------------------------------------------------------------------
int main() {
    map<std::string, size_t> zodziu_sk;
    std::map <std::string, size_t> linkas;
    map<std::string, std::map<size_t, size_t>> references;
    ifstream fd("test.txt");
    ofstream fr("rez.txt");
    nuskaityti(fd , zodziu_sk , references, linkas);
    isvesti(fr , zodziu_sk , references, linkas);
    return 0;
}