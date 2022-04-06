--get player
require("gameAssets.player")
require("gameAssets.block")
--setup Entity List
Entities = {}

--Add Player To Entity List, it will be rendered and processed on the Engine
Entities[0] = Player
--Same With Block and etc..
Entities[1] = Block