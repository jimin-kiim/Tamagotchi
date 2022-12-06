﻿#include "Tamagotchi.h"
#include "Throwings.h"
#include "Throwings_Gen.h"
#include "ScoreAndLife.h"

void Tamagotchi::moveLeft(void) {
    if (tamagotchi.getPosition().x <= 0.0f) {
        return;
    }
    assert(img.loadFromFile("img/l_tamagotchi_img.png"));
    tamagotchi.setTexture(img);
    tamagotchi.move(-10.0f, 0.0f);
}

void Tamagotchi::moveRight(void) {
    if (tamagotchi.getPosition().x >= 320.0f - 30.0f) {
        return;
    }
    assert(img.loadFromFile("img/r_tamagotchi_img.png"));
    tamagotchi.setTexture(img);
    tamagotchi.move(10.0f, 0.0f);
}

void Tamagotchi::update(Throwings_Gen& _throwings, ScoreAndLife& _score)
{
    if (this->getHitted() == true) {
        if (clock.getElapsedTime().asMilliseconds() > 500) {

            assert(img.loadFromFile("img/l_tamagotchi_img.png"));
            tamagotchi.setTexture(img);

            this->setHitted(false);
        }
    }
    if (_throwings.checkHit(tamagotchi.getGlobalBounds(), _score) == true) {
        assert(img.loadFromFile("img/hit_tamagotchi_img.png"));
        tamagotchi.setTexture(img);
        this->setHitted(true);
        clock.restart();
    }
}
void Tamagotchi::draw(RenderWindow& _window) {
    _window.draw(tamagotchi);
}
bool Tamagotchi::getHitted(void) {
    return this->hitted;
}
void Tamagotchi::setHitted(bool boolean) {
    this->hitted = boolean;
}
int Tamagotchi::getPos() {
    return tamagotchi.getPosition().x;
}