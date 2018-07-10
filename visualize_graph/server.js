const express = require('express');
const app = express();
const server = require('http').Server(app);
const io = require('socket.io')(server);
const path = require('path');
const fs = require('fs');

const PORT = 8082;

app.use(express.static(path.join(__dirname, 'public')));

const readFileAndSend = (socket) => {
    fs.readFile('./graph.json', (error, data) => {
        if(error){
            console.log(error.message);
        }
        else{
            let graph = JSON.parse(data.toString());
            let nodes = [];
            let edges = [];

            graph.forEach((node, index) => {
                nodes.push({
                    id: index,
                    label: index.toString()
                });
                node.forEach((conn,i) => {
                    let tempEdge = {
                        from:index,
                        to: conn[0],
                        label: conn[1].toString()
                    };
            
            
                    if(edges.length != 0){
                        let isRepeated = false;
                        for(let i=0;i<edges.length;i++){
                            if(edges[i].to == tempEdge.from && edges[i].from == tempEdge.to){
                                isRepeated = true;
                                break;
                            }
                        }
                        if(!isRepeated){
                            edges.push(tempEdge);
                        }
                    }
                    else{
                        edges.push(tempEdge);
                    }
                });
            });

            socket.emit('some', {
                nodes: nodes,
                edges: edges
            });
        }
    });
}

io.on('connection', (socket) => {
    console.log("client connected");
    readFileAndSend(socket);

    fs.watch('./graph.json', (eventType, filename) => {
        console.log(eventType);
        readFileAndSend(socket);
    });

});


server.listen(PORT, (error) => {
    if(error) throw error;

    console.log("Server running on port " + PORT);
});




