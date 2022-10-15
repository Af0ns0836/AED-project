#include <iostream>
#include "UC.h"
using namespace std;

UC ALGA, AM1, FP, FSC, MD, AED, BD, F2, SO, LDTS, FSI, IPC, LBAW, PFL, RC, UP;

void setUCs() {         //first semester UC's only
    ALGA.setCode("L.EIC001"); ALGA.setCredits(4.5);
    AM1.setCode("L.EIC002"); AM1.setCredits(6);
    FP.setCode("L.EIC003"); FP.setCredits(6);
    FSC.setCode("L.EIC004"); FP.setCredits(6);
    MD.setCode("L.EIC005"); MD.setCredits(6);
    AED.setCode("L.EIC011"); AED.setCredits(6);
    BD.setCode("L.EIC012"); BD.setCredits(6);
    F2.setCode("L.EIC013"); F2.setCredits(4.5);
    SO.setCode("L.EIC014"); SO.setCredits(6);
    LDTS.setCode("L.EIC015"); LDTS.setCredits(6);
    FSI.setCode("L.EIC021"); FSI.setCredits(6);
    IPC.setCode("L.EIC022"); IPC.setCredits(4.5);
    LBAW.setCode("L.EIC023"); LBAW.setCredits(6);
    PFL.setCode("L.EIC024"); PFL.setCredits(6);
    RC.setCode("L.EIC0025"); RC.setCredits(6);
    UP.setCode("UP001"); UP.setCredits(1.5);
}

int main() {
    setUCs();
    cout << "AED tem a sigla " << AED.getCode() << " e vale " << AED.getCredits() << " creditos." << endl;
    return 0;
}
