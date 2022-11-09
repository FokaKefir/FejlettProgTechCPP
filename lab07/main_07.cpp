#include <iostream>
#include "Playlist.h"

using namespace std;

int main() {
    Video v1("T2QvVBSfagU","A Turista odamegy a Paraszthoz", 0.44, "Kockasajt", 20150625);
    Video v2("MTY1Kje0yLg", "Gravity Visualized", 9.57, "apbiolghs", 20120310);
    Video v3("tjf-1BxpR9c", "NVIDIA RTX and GameWorks Ray Tracing Technology", 8.17, "NVIDIA GeForce", 20180321);
    Video v4("fHFhorJnAEI", "See invisible motion; hear silent sound. Cool?", 13.22, "TED", 20141223);
    Video v5("1wAaI_6b9JE", "Four Dimensional Maths: Things to See and Hear in the Fourth Dimension", 61.39, "The Royal Institution", 20150225);
    Video v6("EekCn4wed1E", "A Hads-on Look at Using Ray Tracing in Games With UE 4.22", 28.35, "Unreal Engine", 20190325);
    Video v7("IUjpoauJcKo", "More adventures in replying to spam", 10.20, "TED Archive", 20170127);
    Video v8("Qjt_MqEOcGM", "Troll' from Goodbye Kansas and Deep Forest Films", 1.33, "Unreal Engine", 20190320);
    Video v9("6MmiaqK342c", "Evolution of NVIDIA GeForce 1999-2017", 13.59, "GameForest", 20171107);

    Playlist unreal(10);
    unreal.setTitle("Unreal");
    unreal.append(& v6);
    unreal.append(& v8);

    Playlist nvidia(10);
    nvidia.setTitle("NVIDIA");
    nvidia.append(& v3);
    nvidia.append(& v9);

    Playlist tech(unreal);
    tech = tech + nvidia;
    tech.setTitle("Tech");

    Playlist all(tech);
    all.append(&v1);
    all.append(&v2);
    all.append(&v4);
    all.append(&v5);
    all.append(&v7);
    all.setTitle("All");

    cout << "Before sort\n";
    cout << unreal << endl;
    cout << nvidia << endl;
    cout << tech << endl;
    cout << all << endl;

    all.sort([](const Video *a, const Video *b){
        return a->getLength() < b->getLength();
    });
    cout << "After sort\n";
    cout << unreal << endl;
    cout << nvidia << endl;
    cout << tech << endl;
    cout << all << endl;
    return 0;

}