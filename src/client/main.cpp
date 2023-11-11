#include <iostream>
#include <cstring>

// Les lignes suivantes ne servent qu'à vérifier que la compilation avec SFML fonctionne
#include <SFML/Graphics.hpp>
#include <state.h>
#include "render.h"

void testSFML() {
    sf::Texture texture;
}

// Fin test SFML 





using namespace std;
using namespace state;

void test();
GameState generateSampleState();


int main(int argc, char *argv[]) {

    if (argc >= 2) {
        if (std::strcmp(argv[1], "hello") == 0) { //comparaison of strings
           std::cout << "hello my dear" << std::endl;
        } 

        else if (std::strcmp(argv[1], "state") == 0) { //comparaison of strings
           std::cout << "lancement des tests" << std::endl;
           test();
           std::cout << "everything is fine" << std::endl;
        } 

        else if (std::strcmp(argv[1], "render") == 0) {
           
             sf::RenderWindow window(sf::VideoMode(1600, 900), "Citadelles");

            GameState gamestate=generateSampleState();
            render::Scene sceneA(render::SceneId::playerA, gamestate);
            render::Scene sceneB(render::SceneId::playerB, gamestate);
            render::Scene sceneC(render::SceneId::playerC, gamestate);
            render::Scene sceneD(render::SceneId::playerD, gamestate);


             while (window.isOpen()) {
                sf::Event event;
                while (window.pollEvent(event)) {
                    sceneA.handleEvent(event);
                    sceneB.handleEvent(event);
                    sceneC.handleEvent(event);
                    sceneD.handleEvent(event);

                    if (event.type == sf::Event::Closed) {
                        window.close();
                    }
                }
            window.clear();

            sceneA.draw(window);  
            window.display();
    }
}

        
        else if (std::strcmp(argv[1], "engine") == 0) {
           
        }

        else {
        // error if no argument
        std::cout << "Wrong command. the correct command is  ../bin/client hello" << std::endl;
        }
        return 0;
    }
    return 1;
}

void test(){
    Card card {"card1", CardType::Military, 2};
    Player player {"player1", PlayerId::PlayerA};
    GameState gameState {std::vector<Player>{player}};
}

GameState generateSampleState() {
    Player playerA {"player1", PlayerId::PlayerA};
    Player playerB {"player2", PlayerId::PlayerB};
    Player playerC {"player3", PlayerId::PlayerC};
    Player playerD {"player4", PlayerId::PlayerD};

    GameState gameState {std::vector<Player>{playerA,playerB,playerC,playerD}};
    return gameState;
}


