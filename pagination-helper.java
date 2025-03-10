import java.util.List;

/*https://www.codewars.com/kata/515bb423de843ea99400000a
5 kyu
 */

public class PaginationHelper<I> {
    List<I> collection;
    int itemsPerPage;

    public PaginationHelper(List<I> collection, int itemsPerPage) {
        this.collection = collection;
        this.itemsPerPage = itemsPerPage;
    }

    public int itemCount() {
        return collection.size();
    }

    public int pageCount() {
        return (itemCount() + itemsPerPage - 1) / itemsPerPage;
    }

    public int pageItemCount(int pageIndex) {
        if (pageIndex < 0 || pageIndex >= pageCount()) {
            return -1;
        }
        return (pageIndex == pageCount() - 1) ? (itemCount() % itemsPerPage == 0 ? itemsPerPage : itemCount() % itemsPerPage) : itemsPerPage;
    }

    public int pageIndex(int itemIndex) {
        if (itemIndex < 0 || itemIndex >= itemCount()) {
            return -1;
        }
        return itemIndex / itemsPerPage;
    }
}
