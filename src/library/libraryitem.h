/* This file is part of Clementine.
   Copyright 2010, David Sansome <me@davidsansome.com>

   Clementine is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   Clementine is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with Clementine.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef LIBRARYITEM_H
#define LIBRARYITEM_H

#include <QString>
#include <QList>

#include "core/simpletreeitem.h"
#include "core/song.h"

class LibraryItem : public SimpleTreeItem<LibraryItem> {
 public:
  enum Type {
    Type_Root,
    Type_Divider,
    Type_Container,
    Type_Song,
    Type_PlaylistContainer,
    Type_SmartPlaylist,
    Type_LoadingIndicator,
  };

  LibraryItem(SimpleTreeModel<LibraryItem>* model)
      : SimpleTreeItem<LibraryItem>(Type_Root, model),
        container_level(-1),
        compilation_artist_node_(NULL) {}

  LibraryItem(Type type, LibraryItem* parent = NULL)
      : SimpleTreeItem<LibraryItem>(type, parent),
        container_level(-1),
        compilation_artist_node_(NULL) {}

  int container_level;
  Song metadata;
  QByteArray smart_playlist_data;
  LibraryItem* compilation_artist_node_;
};

#endif  // LIBRARYITEM_H
