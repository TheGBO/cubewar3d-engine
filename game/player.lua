Player = {
    x=0,
    y=0,
    z=0,
    s=10
}

function Player:Tick()
    Player.x = Player.x + 0.01
end

function Player:Render()
    setDrawColor(1,0,0)
    drawQuad(Player.x,Player.y,Player.z,Player.s)
end