#pragma once

#include "../madwolf/typedefs.h"

/// @brief Represents a server room record in the system.
typedef struct ServerRoomRec
{
	struct ServerRoomRec *nextRoom; ///< Pointer to the next room in the linked list.
	struct ServerRoomRec *prevRoom; ///< Pointer to the previous room in the linked list.
	short roomID;                   ///< Unique identifier for the room.
	ushort flags;                   ///< Flags associated with the room.
	ushort maxOccupancy;            ///< Maximum occupancy of the room.
	ushort width;                   ///< Width of the room.
	ushort height;                  ///< Height of the room.
	char name[65];                  ///< Name of the room.
	char description[512];          ///< Description of the room.
	char source[512];               ///< Source of the room.
} ServerRoomRec;

/**
 * @brief Get the ID of a server room.
 *
 * @param room Pointer to the ServerRoomRec structure representing the room.
 * @return The ID of the room.
 */
short RmGetID(const ServerRoomRec *room);

/**
 * @brief Get the dimensions of a server room.
 *
 * @param room Pointer to the ServerRoomRec structure representing the room.
 * @param width Pointer to a ushort variable to store the width of the room.
 * @param height Pointer to a ushort variable to store the height of the room.
 */
void RmGetRoomDim(const ServerRoomRec *room, ushort *width, ushort *height);

bool RmMayLooseProps(const ServerRoomRec *room);

/**
 * @brief Check if a player may spoof in a server room.
 *
 * @param room Pointer to the ServerRoomRec structure representing the room.
 * @return True if the player may spoof in the room, false otherwise.
 */
bool RmMaySpoof(const ServerRoomRec *room);

/**
 * @brief Check if a player may whisper in a server room.
 *
 * @param room Pointer to the ServerRoomRec structure representing the room.
 * @return True if the player may whisper in the room, false otherwise.
 */
bool RmMayWhisper(const ServerRoomRec *room);

/**
 * @brief Convert a room name to its corresponding ID.
 *
 * @param name The name of the room.
 * @return The ID of the room, or 0 if not found.
 */
short RmNameToID(const char *name);

/**
 * @brief Get the next room in the linked list.
 *
 * @param room Pointer to the ServerRoomRec structure representing the current room.
 * @return Pointer to the next room in the linked list, or NULL if there is no next room.
 */
ServerRoomRec *RmNextRoom(const ServerRoomRec *room);

/**
 * @brief Get the first room in the linked list.
 *
 * @return Pointer to the first room in the linked list, or NULL if there are no rooms.
 */
ServerRoomRec *RmStartIterator();
