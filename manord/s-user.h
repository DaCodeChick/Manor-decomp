#include "../madwolf/network.h"
#include "s-room.h"

/// @brief User record structure.
typedef struct ServerUserRec
{
	struct ServerUserRec *nextUser; ///< Pointer to the next user in the linked list.
	struct ServerUserRec *prevUser; ///< Pointer to the previous user in the linked list.
	char address[32];               ///< User's IP address.
	char name[32];                  ///< User's name.
	uint flags;                     ///< User flags.
	ushort groupID;                 ///< User's group ID.
	ushort userID;                  ///< User's ID.
	ServerRoomRec *room;            ///< Room the user is in.
	Connection *connection;         ///< User's connection.
	bool waitingForDisconnect;      ///< Whether the user is waiting for disconnection.
	ushort width;                   ///< User's width.
	ushort height;                  ///< User's height.
	ushort voice;                   ///< User's voice.
} ServerUserRec;

/// @brief User record structure for authentication.
typedef struct ServerAuthUserRec
{
	struct ServerAuthUserRec *next; ///< Pointer to the next user in the linked list.
	char name[32];                  ///< User's name.
	byte encryptedName[32];         ///< User's encrypted name.
} ServerAuthUserRec;

/**
 * @brief Check if the user is valid.
 *
 * @param user Pointer to the user record.
 * @return true if the user is valid, false otherwise.
 */
bool UsIsUser(const ServerUserRec *user);

/**
 * @brief Check if the user is valid and return a pointer to the user record.
 *
 * @param user Pointer to the user record.
 * @return Pointer to the user record if valid, NULL otherwise.
 */
ServerUserRec *usIsUser(const ServerUserRec *user);
