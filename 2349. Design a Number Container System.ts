class SortedSet {
  private items: number[];

  constructor() {
    this.items = [];
  }

  private findInsertionIndex(value: number): number {
    let left = 0, right = this.items.length;

    while (left < right) {
        const mid = Math.floor((left + right) / 2);

        if (this.items[mid] < value) left = mid + 1;

        else right = mid;
    }

    return left;
  }

  add(value: number): void {
    if (!this.items.includes(value)) {
        this.items.splice(this.findInsertionIndex(value), 0, value);
    }
  }

  delete(value: number): void {
    const index = this.items.indexOf(value);
    
    if (index !== -1) {
      this.items.splice(index, 1);
    }
  }

  first(): number | undefined {
    return this.items[0];
  }

  isEmpty(): boolean {
    return this.items.length === 0;
  }
}


class NumberContainers {
  private index_num: Map<number, number>;
  private num_index: Map<number, SortedSet>;

  constructor() {
    this.index_num = new Map();
    this.num_index = new Map();
  }

  change(index: number, number: number): void {
    if (this.index_num.has(index)) {
      const old_number = this.index_num.get(index)!;

      if (old_number !== number) {
        this.num_index.get(old_number)?.delete(index);

        if (this.num_index.get(old_number)?.isEmpty()) {
          this.num_index.delete(old_number);
        }
      }
    }

    this.index_num.set(index, number);

    if (!this.num_index.has(number)) {
      this.num_index.set(number, new SortedSet());
    }

    this.num_index.get(number)!.add(index);
  }

  find(number: number): number {
    return this.num_index.has(number) ? this.num_index.get(number)!.first() ?? -1 : -1;
  }
}


/**
 * Your NumberContainers object will be instantiated and called as such:
 * var obj = new NumberContainers()
 * obj.change(index,number)
 * var param_2 = obj.find(number)
 */
