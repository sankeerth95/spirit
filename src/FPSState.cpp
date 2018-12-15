//
// Created by sankeerth on 11/17/18.
//

#include <GL/glew.h>
#include <iostream>
#include "FPSState.h"
#include "Controller.h"


FPSState::FPSState() {

    fp = new FirstPerson();
    hud = new HUD();

}

void FPSState::set_shaders() {

    fp->init();
    hud->init();
}


void FPSState::update() {

    fp->update();
    hud->update();
}


void FPSState::draw() {

    fp->draw();
    hud->draw();

}
