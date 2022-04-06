Player = {
    x=0,
    y=0,
    z=0,
    s=10,
    a=0
}

function Player:Tick()
    setCameraPosition(-Player.x,Player.y-15,-Player.z-50)
    if isKeyDown("d") then
        Player.a = Player.a - 0.1
    end
    if isKeyDown("a") then
        Player.a = Player.a + 0.1
    end
    if isKeyDown("w") then
        Player.z = Player.z + math.cos(math.rad(Player.a)) * 0.05
        Player.x = Player.x + math.sin(math.rad(Player.a)) * 0.05
    end
    if isKeyDown("s") then
        Player.z = Player.z - math.cos(math.rad(Player.a)) * 0.05
        Player.x = Player.x - math.sin(math.rad(Player.a)) * 0.05
    end
end

function Player:Render()
    setDrawColor(1,0.5,0)
    solidCube(0,0,0,Player.s)
    setDrawColor(0,0,0)
    drawQuad(-3,0,Player.s/1.85,1)
    drawQuad(3,0,Player.s/1.85,1)
end