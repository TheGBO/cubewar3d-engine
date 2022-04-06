Block = {
    x=0,
    y=0,
    z=-50,
    s=10,
    a=0
}

function Block:Tick()
    
end

function Block:Render()
    translate(Block.x,Block.y,Block.z)
    setDrawColor(0,.3,0)
    solidCube(0,0,0,Block.s)
end