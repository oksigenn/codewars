/*https://www.codewars.com/kata/57675f3dedc6f728ee000256
6 kyu
*/

fn tower_builder(floors: usize, block_size: (usize, usize)) -> Vec<String> {
    let (width, height) = block_size;
    let mut tower = Vec::new();
    
    for floor in 1..=floors {
        let blocks = 2 * floor - 1;
        let stars = "*".repeat(blocks * width);
        let max_width = 2 * floors - 1;
        let padding = (max_width * width - stars.len()) / 2;
        let line = " ".repeat(padding) + &stars + &" ".repeat(padding);
        
        for _ in 0..height {
            tower.push(line.clone());
        }
    }
    
    tower
}