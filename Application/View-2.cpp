#include "View-2.h"
#include <iostream>

/**
 * Constructor
 * @param _controller Application controller
 */
View2::View2(Controller& _controller)
    : View("Filtre gaussien"), controller(_controller)
{
    controller.addObserver(this);
}

/**
 * Notification function of the view
 */
void View2::notify()
{
    if (controller.getCurrentScreen() == 2)
        display();
}

/**
 * Displays the view
 */
void View2::display()
{
    int x = 0;
    do
    {
        clear();
        View::display();

        std::cout << "\tDonnez une valeur:" << std::endl;
        std::cout << "\t\tIl est conseille une valeur entre 1 et 10" << std::endl << std::endl;

        std::cout << "\t-----------------------------------------------------------" << std::endl;
        std::cout << "\t0. Retour" << std::endl;
        std::cout << std::endl;

        std::cin.clear();
        std::cin >> x;

        if (x != 0)
        {
            controller.filtreGaussian(x);
            controller.updateGhost("Filtre gaussien");

            clear();
            View::display();

            std::cout << "\tVoulez vous garder la modification ?" << std::endl;
            std::cout << "\t\t1. Oui" << std::endl;
            std::cout << "\t\t0. Non" << std::endl << std::endl;

            int y;
            std::cin.clear();
            std::cin >> y;

            if (y == 1)
            {
                controller.ghostToImg();
                x = 0;
            }
            else
            {
                x = 2;
            }
            controller.setScreen(x);
        }
        else 
        {
            controller.setScreen(x);
        }
    } while (x != 0);
}