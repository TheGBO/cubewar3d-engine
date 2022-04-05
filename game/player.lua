Player = {
    x=0,
    y=0,
    z=0,
    s=10
}

function Player:Tick()
    Player.x = Player.x + 0.001
end

function Player:Render()
    setDrawColor(0,0,1)
    solidCube(Player.x,Player.y,Player.z,Player.s)
    setDrawColor(1,0,0)
    drawQuad(0,0,1,Player.s)
end