#ifndef PLAYER_H
#define PLAYER_H
#include <boost/format.hpp>
#include "actor.h"
#include "inventory.h"
namespace FAWorld
{
    class Player: public Actor
    {
        STATIC_HANDLE_NET_OBJECT_IN_CLASS()

        public:
            Player();
            Player(const std::string& className, const DiabloExe::CharacterStats& charStats);
            virtual ~Player();
            Inventory mInventory;
            void setSpriteClass(std::string className);
            bool talk(Actor * actor);
            void updateSprites();

            virtual size_t getBasePriority()
            {
                return 10;
            }

        private:
            void init(const std::string& className, const DiabloExe::CharacterStats& charStats);

            std::string mClassName;

            friend class Inventory;

            template <class Stream>
            Serial::Error::Error faSerial(Stream& stream)
            {
                serialise_as_parent_class(Actor);
                return Serial::Error::Success;
            }

            friend class Serial::WriteBitStream;
            friend class Serial::ReadBitStream;
    };
}
#endif
